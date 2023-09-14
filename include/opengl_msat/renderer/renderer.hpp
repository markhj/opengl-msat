#ifndef OPENGL_MSAT_RENDERER_HPP
#define OPENGL_MSAT_RENDERER_HPP

#include <iostream>
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/shared/render_types.hpp"
#include "opengl_msat/context/context.hpp"
#include "opengl_msat/window/window.hpp"
#include "opengl_msat/timer/timer.hpp"

class Renderer {
public:
    Renderer(Window& window, Timer* timer, RenderSettings* settings)
        : window(window), timer(timer), settings(settings) {
        applySettings();
    }

    Renderer(Window& window)
            : window(window), timer(nullptr), settings(nullptr) {
        applySettings();
    }

    void applySettings() const;

    void render(VAO& vao);

    void render(VAO vao, DrawMode drawMode);

    void render(VAO& vao, DrawMode drawMode, unsigned int from, unsigned int count);

    void loop(std::function<void(Renderer*)> iter);

    void clear() const;
private:
    Window& window;

    Timer* timer;

    RenderSettings* settings;
};

#endif
