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
    Renderer(Window& window, Timer& timer) : window(window), timer(timer) {}

    void render(std::function<void()> iter)
    {
        while (window.keepOpen())
        {
            timer.start();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            iter();

            glDrawArrays(GL_TRIANGLES, 0, 3);

            window.swapAndPoll();

            timer.end();
        }
    }
private:
    Window& window;

    Timer& timer;
};

#endif
