#ifndef OPENGL_MSAT_ANIMATION_HPP
#define OPENGL_MSAT_ANIMATION_HPP

#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <optional>
#include <functional>
#include "opengl_msat/timer/timer.hpp"
#include "opengl_msat/contracts/animateable.hpp"
#include "opengl_msat/geometry/vectors.hpp"
#include "opengl_msat/traits/dev_messaging.hpp"

enum TimingFunction {
    Linear,
    Easing,
};

template <typename T>
class AnimationStep {
public:
    float from, to;
    std::optional<T> tFrom;
    std::optional<T> tTo;
    std::optional<std::function<T(float)>> function;
};

template <typename T>
class AnimationBlueprint {
public:
    AnimationBlueprint<T>& step(float pctFrom, float pctTo, T to)
    {
        steps.push_back({
            .from = pctFrom,
            .to = pctTo,
            .tTo = to
        });

        return *this;
    }

    AnimationBlueprint<T>& step(float pctFrom, float pctTo, T from, T to)
    {
        steps.push_back({
            .from = pctFrom,
            .to = pctTo,
            .tFrom = from,
            .tTo = to
        });

        return *this;
    }

    AnimationBlueprint<T>& step(float pctFrom, float pctTo, std::function<T(float)> func)
    {
        steps.push_back({
            .from = pctFrom,
            .to = pctTo,
            .function = func,
        });

        return *this;
    }

    void animate(float pct, float realPct, Animateable<T>* target)
    {
        for (AnimationStep step : steps) {
            if (step.from <= pct && pct <= step.to) {
                float usePct = 100 * (pct - step.from) / (step.to - step.from);
                if (step.function.has_value()) {
                    latest = step.function.value()(usePct);
                    target->animate(latest.value());
                } else if (step.tFrom.has_value() && step.tTo.has_value()) {
                    target->animate(usePct,
                                    step.tFrom.value(),
                                    step.tTo.value()
                                    );
                    if (realPct == 100) {
                        latest = step.tTo.value();
                    }
                } else if (step.tTo.has_value() && latest.has_value()) {
                    target->animate(usePct,
                                    latest.value(),
                                    step.tTo.value()
                    );
                    if (realPct == 100) {
                        latest = step.tTo.value();
                    }
                }
            }
        }
    }

private:
    std::vector<AnimationStep<T>> steps;

    std::optional<T> latest;

};

template <typename T>
class Animation :
        public DeveloperMessaging {
public:
    Animation(Timer* timer,
              AnimationBlueprint<T>* blueprint,
              std::vector<Animateable<T>*> targets)
              : timer(timer), blueprint(blueprint), targets(targets)
              { }

    Animation(Timer* timer,
              AnimationBlueprint<T>* blueprint,
              std::vector<Animateable<T>*> targets,
              float duration)
              : timer(timer), blueprint(blueprint), targets(targets), duration(duration)
              { }

    Animation<T> setDuration(float value)
    {
        if (isStarted()) {
            return *this;
        }

        duration = value;

        return *this;
    }

    Animation<T> setIterations(unsigned int value)
    {
        if (isStarted()) {
            return *this;
        }

        iterations = value;

        return *this;
    }

    Animation<T> infinite()
    {
        infiniteIteration = true;

        return *this;
    }

    Animation<T> setTimingFunction(std::function<float(float)> func)
    {
        if (func(100) != 100) {
            warn("Custom timing function does not return 100 when 100 is given.");
        }

        timingFunction = func;

        return *this;
    }

    Animation<T> setTimingFunction(TimingFunction func)
    {
        switch (func) {
            case TimingFunction::Linear:
                setTimingFunction([](float pct) {
                    return pct;
                });
                break;
            case TimingFunction::Easing:
                setTimingFunction([](float pct) {
                    pct = std::clamp(pct / 100.0, 0.0, 1.0);
                    float easedValue;
                    if (pct < 0.5) {
                        easedValue = 4.0 * pow(pct, 3);
                    } else {
                        easedValue = 1.0 + 4.0 * pow(pct - 1.0, 3);
                    }
                    return easedValue * 100.0;
                });
                break;
        }
        return *this;
    }

    void tick()
    {
        if (!isStarted() || !isRunning()) {
            return;
        }

        pos += timer->getDeltaTime();
        if (pos > duration) {
            pos = duration;
        }

        float realPct = 100 * pos / duration;
        float usePct = realPct;
        if (timingFunction.has_value()) {
            usePct = timingFunction.value()(usePct);
        }

        for (Animateable<T>* target : targets) {
            blueprint->animate(usePct, realPct, target);
        }

        checkForStop();
    }

    void start()
    {
        rewind();
        currentIteration = 1;
        started = true;
        running = true;
    }

    void resume()
    {
        if (!isStarted()) {
            return;
        }

        running = true;
    }

    void pause()
    {
        if (!isStarted()) {
            return;
        }

        running = false;
    }

    void stop()
    {
        rewind();
        started = false;
        running = false;
    }

    void rewind()
    {
        pos = 0.0;
    }

    bool isStarted()
    {
        return started;
    }

    bool isRunning()
    {
        return running;
    }

private:
    Timer *timer;

    std::vector<Animateable<T>*> targets;

    AnimationBlueprint<T>* blueprint;

    // Duration of the animation in seconds
    // Animation starts counting at first tick
    float duration = 5.0;

    bool started = false;

    bool running = false;

    bool infiniteIteration = false;

    float pos = 0.0;

    unsigned int iterations = 1, currentIteration = 0;

    std::optional<std::function<float(float)>> timingFunction;

    void checkForStop()
    {
        if (pos < duration) {
            return;
        }

        if (currentIteration >= iterations && !infiniteIteration) {
            stop();
        } else {
            currentIteration++;
            rewind();
        }
    }

};

#endif
