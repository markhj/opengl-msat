#ifndef OPENGL_MSAT_RENDERER_HPP
#define OPENGL_MSAT_RENDERER_HPP

#include <iostream>
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/types/render_types.hpp"
#include "opengl_msat/context/context.hpp"
#include "opengl_msat/window/window.hpp"
#include "opengl_msat/timer/timer.hpp"
#include "renderstate.hpp"
#include "opengl_msat/camera/camera.hpp"

class Renderer {
public:
    Renderer(Window* window, Camera* camera, Timer* timer, RenderState state)
        : window(window), camera(camera), timer(timer), renderState(state)
        {
        }

    void render(VAO& vao);

    void render(VAO vao, DrawMode drawMode);

    void render(VAO& vao, DrawMode drawMode, unsigned int from, unsigned int count);

    void loop(std::function<void(Renderer*)> iter);

    void clear() const;

    RenderState* state();

    Camera* getCamera();

    void swapState(RenderState state, std::function<void(Renderer*)> iter);

    bool resetState = true;

private:
    Window* window;

    Camera* camera;

    Timer* timer;

    RenderState renderState;

};

#endif
