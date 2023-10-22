#include "opengl_msat/timer/timer.hpp"

#include <cmath>
#include <iostream>

void Timer::start()
{
    startTime = std::chrono::high_resolution_clock::now();

    if (!absoluteStarted) {
        absoluteStartTime = std::chrono::high_resolution_clock::now();
        absoluteStarted = true;
    }
}

void Timer::end()
{
    deltaTime = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime).count();
    hasDeltaTime = true;

    if (trackDelta != nullptr) {
        *trackDelta += static_cast<float>(deltaTime);
    }
}

double Timer::getDeltaTime() const
{
    return deltaTime;
}

double Timer::getDeltaTimeOrFallback(double fallback) const
{
    return hasDeltaTime ? deltaTime : fallback;
}

unsigned int Timer::getFramesPerSecond() const
{
    return getFramesPerSecond(false);
}

double Timer::getElapsedTime() const
{
    if (!absoluteStarted) {
        return 0.0;
    }

    return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - absoluteStartTime).count();
}

void Timer::endRenderTime()
{
    renderTime = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime).count();
}

double Timer::getRenderTime() const
{
    return renderTime;
}

unsigned int Timer::getFramesPerSecond(bool trueRender) const
{
    return static_cast<unsigned int>(floor(1 / (trueRender ? getRenderTime() : getDeltaTime())));
}

void Timer::trackDeltaTimeOn(float *target)
{
    trackDelta = target;
}
