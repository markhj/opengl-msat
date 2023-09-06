#include "opengl_msat/timer/timer.hpp"

#include <cmath>

void Timer::start()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::end()
{
    deltaTime = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime).count();
}

double Timer::getDeltaTime() const
{
    return deltaTime;
}

unsigned int Timer::getFramesPerSecond() const
{
    return static_cast<unsigned int>(floor(1 / getDeltaTime()));
}
