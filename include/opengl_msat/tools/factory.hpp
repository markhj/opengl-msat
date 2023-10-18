#ifndef OPENGL_MSAT_FACTORY_HPP
#define OPENGL_MSAT_FACTORY_HPP

#include "opengl_msat/window/window.hpp"
#include "opengl_msat/timer/timer.hpp"
#include "opengl_msat/types/projections.hpp"

class Factory {
public:
    Window* window;
    Timer* timer;
    Camera* camera;

    Factory(Window* window, Camera* camera, Timer* timer)
        : window(window), camera(camera), timer(timer)
        { }

    [[nodiscard]] Projection createProjection() const
    {
        return {window, camera};
    }

};

#endif
