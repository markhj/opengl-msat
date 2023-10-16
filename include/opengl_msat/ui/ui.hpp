#ifndef OPENGL_MSAT_UI_HPP
#define OPENGL_MSAT_UI_HPP

#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/renderer/renderer.hpp"

class UI {
public:
    UI(Window* window, Camera* camera)
        : vao(VAO()), vbo(VBO()), shader(ShaderProgram()), projection(Projection(window, camera))
    {
        std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D,
                                                    VertexAttribute::ColorRGBA };

        vbo.setVertices({});
        vao.associate(vbo, attributes);

        projection.orthographic();

        VertexShaderBuilder hudVsb(attributes);
        hudVsb.projection = &projection;

        FragmentShaderBuilder fsb(attributes);

        shader.fromBuilder(hudVsb);
        shader.fromBuilder(fsb);
        shader.compile();
    }

    void render(Renderer* renderer)
    {
        Camera* camera = renderer->getCamera();

        float currentNear = camera->zNear,
                currentFar = camera->zFar;

        RenderState state;
        state.enable(RenderOption::DepthTesting);
        state.enable(RenderOption::Blend);
        state.setBlendingFunction();

        camera->zNear = -1.0;
        camera->zFar = 1.0;

//        renderer->swapState(state, [&](Renderer* renderer) {
            shader.uniform(projection);
            shader.bind();

            Context::with(shader, [&] {
                renderer->render(vao);
            });
//        });

        camera->zNear = currentNear;
        camera->zFar = currentFar;
    }

    void setVertices(std::vector<GLfloat> vertices)
    {
        vbo.setVertices(vertices);
        vbo.upload();
    }

private:
    ShaderProgram shader;

    VAO vao;

    VBO vbo;

    Projection projection;

};

#endif
