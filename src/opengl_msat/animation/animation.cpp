#include "opengl_msat/animation/animation.hpp"

template<typename T>
void AnimationBlueprint<T>::animate(float pct, float realPct, Animateable<T> *target)
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

template<typename T>
AnimationBlueprint<T> &AnimationBlueprint<T>::step(float pctFrom, float pctTo, std::function<T(float)> func)
{
    validateInterval(pctFrom, pctTo);

    steps.push_back({
                            .from = pctFrom,
                            .to = pctTo,
                            .function = func,
                    });

    return *this;
}

template<typename T>
AnimationBlueprint<T> &AnimationBlueprint<T>::step(float pctFrom, float pctTo, T from, T to)
{
    validateInterval(pctFrom, pctTo);

    steps.push_back({
                            .from = pctFrom,
                            .to = pctTo,
                            .tFrom = from,
                            .tTo = to
                    });

    return *this;
}

template<typename T>
AnimationBlueprint<T> &AnimationBlueprint<T>::step(float pctFrom, float pctTo, T to)
{
    validateInterval(pctFrom, pctTo);

    steps.push_back({
                            .from = pctFrom,
                            .to = pctTo,
                            .tTo = to
                    });

    return *this;
}

template<typename T>
bool AnimationBlueprint<T>::isIntervalOccupied(float from, float to) const
{
    for (auto step : steps) {
        if (from >= step.from && from <= step.to) {
            return true;
        }

        if (to >= step.from && to <= step.to) {
            return true;
        }

        if (from <= step.from && to >= step.from) {
            return true;
        }

        if (from <= step.to && to >= step.to) {
            return true;
        }
    }

    return false;
}

template<typename T>
void AnimationBlueprint<T>::validateInterval(float from, float to)
{
    if (isIntervalOccupied(from, to)) {
        warn("You have overlapping intervals in an animation.");
    }
}

template<typename T>
void Animation<T>::tick()
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

template<typename T>
Animation<T> Animation<T>::setTimingFunction(TimingFunction func)
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

template<typename T>
Animation<T> Animation<T>::setTimingFunction(std::function<float(float)> func)
{
    if (func(100) != 100) {
        warn("Custom timing function does not return 100 when 100 is given.");
    }

    timingFunction = func;

    return *this;
}

template<typename T>
Animation<T> Animation<T>::infinite()
{
    infiniteIteration = true;

    return *this;
}

template<typename T>
Animation<T> Animation<T>::setIterations(unsigned int value)
{
    if (isStarted()) {
        return *this;
    }

    iterations = value;

    return *this;
}

template<typename T>
Animation<T> Animation<T>::setDuration(float value)
{
    if (isStarted()) {
        return *this;
    }

    duration = value;

    return *this;
}

template<typename T>
Animation<T>::Animation(Timer *timer, AnimationBlueprint<T> *blueprint, std::vector<Animateable<T> *> targets,
                        float duration)
        : timer(timer), blueprint(blueprint), targets(targets), duration(duration)
{

}

template<typename T>
Animation<T>::Animation(Timer *timer, AnimationBlueprint<T> *blueprint, std::vector<Animateable<T> *> targets)
        : timer(timer), blueprint(blueprint), targets(targets)
{

}

template<typename T>
void Animation<T>::checkForStop()
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

template<typename T>
bool Animation<T>::isRunning()
{
    return running;
}

template<typename T>
bool Animation<T>::isStarted()
{
    return started;
}

template<typename T>
void Animation<T>::rewind()
{
    pos = 0.0;
}

template<typename T>
void Animation<T>::stop()
{
    rewind();
    started = false;
    running = false;
}

template<typename T>
void Animation<T>::pause()
{
    if (!isStarted()) {
        return;
    }

    running = false;
}

template<typename T>
void Animation<T>::resume()
{
    if (!isStarted()) {
        return;
    }

    running = true;
}

template<typename T>
void Animation<T>::start()
{
    rewind();
    currentIteration = 1;
    started = true;
    running = true;
}
