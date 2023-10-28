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

/**
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/animation-enums/
 * @see https://opengl-msat.readthedocs.io/en/latest/animation/timing-functions/
 */
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

/**
 * Animation blueprint
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/animation/blueprint/
 */
template <typename T>
class AnimationBlueprint : DeveloperMessaging {
public:
    AnimationBlueprint<T>& step(float pctFrom, float pctTo, T to);

    AnimationBlueprint<T>& step(float pctFrom, float pctTo, T from, T to);

    AnimationBlueprint<T>& step(float pctFrom, float pctTo, std::function<T(float)> func);

    void animate(float pct, float realPct, Animateable<T>* target);

private:
    std::vector<AnimationStep<T>> steps;

    std::optional<T> latest;

    void validateInterval(float from, float to);

    bool isIntervalOccupied(float from, float to) const;

};

/**
 * Animation
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/animation/animation/
 */
template <typename T>
class Animation :
        DeveloperMessaging {
public:
    Animation(Timer* timer,
              AnimationBlueprint<T>* blueprint,
              std::vector<Animateable<T>*> targets);

    Animation(Timer* timer,
              AnimationBlueprint<T>* blueprint,
              std::vector<Animateable<T>*> targets,
              float duration);

    Animation<T> setDuration(float value);

    Animation<T> setIterations(unsigned int value);

    Animation<T> infinite();

    Animation<T> setTimingFunction(std::function<float(float)> func);

    Animation<T> setTimingFunction(TimingFunction func);

    void tick();

    void start();

    void resume();

    void pause();

    void stop();

    void rewind();

    bool isStarted();

    bool isRunning();

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

    void checkForStop();

};

template class AnimationBlueprint<Vec3>;
template class Animation<Vec3>;

#endif
