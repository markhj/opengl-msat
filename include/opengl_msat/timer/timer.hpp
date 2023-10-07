#ifndef OPENGL_MSAT_TIMER_HPP
#define OPENGL_MSAT_TIMER_HPP

#include <chrono>

class Timer {
public:
    void start();

    void end();

    void endRenderTime();

    [[nodiscard]] double getDeltaTime() const;

    [[nodiscard]] double getDeltaTimeOrFallback(double fallback) const;

    [[nodiscard]] unsigned int getFramesPerSecond() const;

    [[nodiscard]] unsigned int getFramesPerSecond(bool trueRender) const;

    [[nodiscard]] double getElapsedTime() const;

    [[nodiscard]] double getRenderTime() const;

private:
    double deltaTime = 0.0,
        renderTime = 0.0;

    bool absoluteStarted = false,
        hasDeltaTime = false;

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

    std::chrono::time_point<std::chrono::high_resolution_clock> absoluteStartTime;
};

#endif
