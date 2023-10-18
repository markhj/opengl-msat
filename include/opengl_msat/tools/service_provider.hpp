#ifndef OPENGL_MSAT_SERVICE_PROVIDER_HPP
#define OPENGL_MSAT_SERVICE_PROVIDER_HPP

#include "opengl_msat/window/window.hpp"
#include "opengl_msat/timer/timer.hpp"
#include "opengl_msat/types/projections.hpp"

class IoCContainer {
public:
    Window* window;
    Timer* timer;
    Camera* camera;

};

class Factory {
public:
    explicit Factory(IoCContainer* iocc) : iocc(iocc) { }

    [[nodiscard]] Projection createProjection() const
    {
        return {iocc->window, iocc->camera};
    }

private:
    IoCContainer* iocc;

};

class ServiceProvider {
public:
    ServiceProvider(Window* window, Camera* camera, Timer* timer)
        : iocc(IoCContainer()),
          fct(Factory(&iocc))
    {
        iocc.window = window;
        iocc.camera = camera;
        iocc.timer = timer;
    }

    Factory& factory()
    {
        return fct;
    }

    IoCContainer* container()
    {
        return &iocc;
    }

private:
    IoCContainer iocc;

    Factory fct;

};

#endif
