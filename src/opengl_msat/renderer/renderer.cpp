#include "opengl_msat/renderer/renderer.hpp"


void Renderer::render(VAO &vao)
{
    vao.bind();

    // @todo Implement support for multiple VBOs, instead of specifically targeting the first
    VBO& vbo = vao.getAssociatedVBOs()[0].get();

    render(vao, DrawMode::Triangles, 0, vbo.count());

    vao.unbind();
}

void Renderer::render(VAO vao, DrawMode drawMode)
{
    vao.bind();

    // @todo Implement support for multiple VBOs, instead of specifically targeting the first
    VBO& vbo = vao.getAssociatedVBOs()[0].get();

    render(vao, drawMode, 0, vbo.count());

    vao.unbind();
}

void Renderer::render(VAO &vao, DrawMode drawMode, unsigned int from, unsigned int count)
{
    vao.bind();
    glDrawArrays(drawMode, from, count);
    vao.unbind();
}

void Renderer::loop(std::function<void(Renderer *)> iter)
{
    while (window.keepOpen())
    {
        if (timer != nullptr) {
            timer->start();
        }

        clear();

        iter(this);

        window.swapBuffers();
        window.pollEvents();

        if (timer != nullptr) {
            timer->end();
        }
    }
}

void Renderer::clear() const
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Renderer::applySettings() const
{
    RenderSettings active = settings == nullptr ? RenderSettings {} : *settings;

    glPointSize(active.pointSize);
    glLineWidth(active.lineSize);
}
