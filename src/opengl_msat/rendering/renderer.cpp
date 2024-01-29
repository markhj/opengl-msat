#include <utility>

#include "opengl_msat/rendering/renderer.hpp"


void Renderer::render(VAO &vao)
{
    vao.bind();

    // @todo Implement support for multiple VBOs, instead of specifically targeting the first
    VAOAssociable& vbo = vao.getAssociatedVBOs()[0].get();

    render(vao,
           DrawMode::Triangles,
           0,
           vbo.countVertices(vao.getAttributesForVBO(&vbo).value()));

    vao.unbind();
}

void Renderer::render(VAO vao, DrawMode drawMode)
{
    vao.bind();

    // @todo Implement support for multiple VBOs, instead of specifically targeting the first
    VAOAssociable& vbo = vao.getAssociatedVBOs()[0].get();

    render(vao,
           drawMode,
           0,
           vbo.countVertices(vao.getAttributesForVBO(&vbo).value()));

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
    renderState.applyAll();

    while (window->keepOpen())
    {
        timer->start();

        if (resetState) {
            renderState.reset();
        }

        window->handleInputs();

        clear();

        iter(this);

        timer->endRenderTime();

        window->swapBuffers();
        window->pollEvents();

        timer->end();
    }
}

void Renderer::clear() const
{
    glClearColor(backgroundColor.r,
                 backgroundColor.g,
                 backgroundColor.b,
                 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

RenderState *Renderer::state()
{
    return &renderState;
}

Camera* Renderer::getCamera()
{
    return camera;
}

void Renderer::swapState(RenderState state, std::function<void(Renderer *)> iter)
{
    RenderState restoreTo = renderState;

    renderState = std::move(state);
    renderState.applyAll();

    iter(this);

    renderState = restoreTo;
    renderState.applyAll();
}
