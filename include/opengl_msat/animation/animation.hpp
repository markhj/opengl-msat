#ifndef OPENGL_MSAT_ANIMATION_HPP
#define OPENGL_MSAT_ANIMATION_HPP

#include <map>
#include <vector>
#include <iostream>
#include "opengl_msat/timer/timer.hpp"
#include "opengl_msat/contracts/animateable.hpp"
#include "opengl_msat/geometry/vectors.hpp"

template <typename T>
class AnimationBlueprint {
public:
    AnimationBlueprint<T>& step(float pct, T prop)
    {
        steps.insert(std::make_pair(pct, prop));
        return *this;
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

    T getFrom(float pct)
    {
        return steps.find(getBefore(pct))->second;
    }

    T getTo(float pct)
    {
        return steps.find(getAfter(pct))->second;
    }

private:
    std::map<float, T> steps;

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

    void setDuration(float value)
    {
        if (isStarted()) {
            return;
        }

        duration = value;
    }

    void setIterations(unsigned int value)
    {
        if (isStarted()) {
            return;
        }

        iterations = value;
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
        float pctFrom = blueprint->getBefore(pct);
        float pctTo = blueprint->getAfter(pct);
        float usePct = 100 * (pct - pctFrom) / (pctTo - pctFrom);

        Vec3 from = blueprint->getFrom(pct);
        Vec3 to = blueprint->getTo(pct);

        for (Animateable<T>* target : targets) {
            target->animate(usePct, from, to);
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

    float pos = 0.0;

    unsigned int iterations = 1, currentIteration = 0;

    void checkForStop()
    {
        if (pos < duration) {
            return;
        }

        if (currentIteration >= iterations) {
            stop();
        } else {
            currentIteration++;
            rewind();
        }
    }

};

#endif
