#ifndef OPENGL_MSAT_TIMER_HPP
#define OPENGL_MSAT_TIMER_HPP

#include <chrono>

class Timer {
public:
    void start();

    void end();

    double getDeltaTime() const;

    unsigned int getFramesPerSecond() const;
private:
    double deltaTime = 0.0f;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif
