#ifndef OPENGL_MSAT_ANIMATION_HPP
#define OPENGL_MSAT_ANIMATION_HPP

#include <map>
#include <vector>
#include <iostream>
#include <optional>
#include <functional>
#include "opengl_msat/timer/timer.hpp"
#include "opengl_msat/contracts/animateable.hpp"
#include "opengl_msat/geometry/vectors.hpp"

template <typename T>
class AnimationStep {
public:
    std::optional<T> value;
    std::optional<std::function<T(float)>> function;
};

template <typename T>
class AnimationBlueprint {
public:
    AnimationBlueprint<T>& step(float pct, T prop)
    {
        steps.insert(std::make_pair(pct, AnimationStep<T> {
            .value = prop,
            }));

        return *this;
    }

    AnimationBlueprint<T>& step(float pctFrom, float pctTo, std::function<T(float)> func)
    {
        steps.insert(std::make_pair(pctFrom, AnimationStep<T> {
            .function = func,
        }));

        steps.insert(std::make_pair(pctTo, AnimationStep<T> {
            .value = func(100),
        }));

        return *this;
    }

    void animate(float pct, Animateable<T>* target)
    {
        float pctFrom = getBefore(pct);
        float pctTo = getAfter(pct);
        float usePct = 100 * (pct - pctFrom) / (pctTo - pctFrom);

        AnimationStep<T> from = steps.find(pctFrom)->second;
        AnimationStep<T> to = steps.find(pctTo)->second;

        if (from.function.has_value()) {
            target->animate(from.function.value()(usePct));
        } else {
            target->animate(usePct,
                            from.function.has_value() ? from.function.value()(100) : from.value.value(),
                            to.value.value());
        }
    }

    float getBefore(float pct)
    {
        float tmp = 0.0;
        for (auto x : steps) {
            if (x.first >= pct) {
                return tmp;
            }
            tmp = x.first;
        }
        return steps.begin()->first;
    }

    float getAfter(float pct)
    {
        for (auto x : steps) {
            if (x.first >= pct) {
                return x.first;
            }
        }
        return steps.end()->first;
    }

private:
    std::map<float, AnimationStep<T>> steps;

};

template <typename T>
class Animation {
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

    void tick()
    {
        if (!isStarted() || !isRunning()) {
            return;
        }

        pos += timer->getDeltaTime();
        if (pos > duration) {
            pos = duration;
        }

        float pct = 100 * pos / duration;

        for (Animateable<T>* target : targets) {
            blueprint->animate(pct, target);
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
