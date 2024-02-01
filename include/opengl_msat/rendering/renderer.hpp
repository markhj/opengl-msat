#ifndef OPENGL_MSAT_RENDERER_HPP
#define OPENGL_MSAT_RENDERER_HPP

#include <iostream>
#include <utility>
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/types/render_types.hpp"
#include "opengl_msat/context/context.hpp"
#include "opengl_msat/window/window.hpp"
#include "opengl_msat/timer/timer.hpp"
#include "renderstate.hpp"
#include "opengl_msat/camera/camera.hpp"
#include "opengl_msat/tools/service_provider.hpp"

/**
 * Renderer
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/render/render/
 */
class Renderer {
public:
    explicit Renderer(Window* window, Camera* camera, Timer* timer)
        : window(window),
          camera(camera),
          timer(timer),
          renderState({})
    {
    }

    Renderer(Window* window, Camera* camera, Timer* timer, RenderState state)
        : window(window),
        camera(camera),
        timer(timer),
        renderState(std::move(state))
    {
    }

    void render(VAO& vao);

    void render(VAO vao, DrawMode drawMode);

    void render(VAO& vao, DrawMode drawMode, unsigned int from, unsigned int count);

    void loop(std::function<void(Renderer*)> iter);

    /**
     * Clear color/depth/stencil buffer
     *
     * @see https://opengl-msat.readthedocs.io/en/latest/render/buffer-clearing/
     */
    void clear() const;

    RenderState* state();

    Camera* getCamera();

    void swapState(RenderState state, std::function<void(Renderer*)> iter);

    bool resetState = true;

    /**
     * Applied by glClearColor which determines the background color
     * where no pixels are actively rendered
     */
    Color backgroundColor = Color(0.0);

private:
    Window* window;

    Camera* camera;

    Timer* timer;

    RenderState renderState;

};

#endif
