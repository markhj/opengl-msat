#ifndef OPENGL_MSAT_GRID_HPP
#define OPENGL_MSAT_GRID_HPP

#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/context/context.hpp"
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/renderer/renderer.hpp"

class Grid {
public:
    Grid() {
        std::vector<VertexAttribute> attributes = {
            VertexAttribute::Position3D,
            VertexAttribute::ColorRGB,
        };

        refresh();

        vao.associate(vbo, attributes);

        VertexShaderBuilder vsb(attributes);
        FragmentShaderBuilder fsb(attributes);

        vsb.setProjection(Projection::Perspective);

        shader = ShaderProgram();
        shader.fromBuilder(vsb);
        shader.fromBuilder(fsb);
        shader.compile();
    }

    void refresh()
    {
        vbo.setVertices({
            0.5, 0.0, -0.2,      0.0, 1.0, 0.0,
            0.0, 0.5, -0.2,      0.0, 1.0, 0.3,
            -0.5, 0.0, -0.2,     0.0, 1.0, 0.6
        });
    }

    void render(Renderer* renderer)
    {
        RenderState state;
        state.enable(RenderOption::DepthTesting);

        renderer->withState(state, [&](Renderer* renderer) {
            shader.uniform(renderer->getCamera());

            Context::safeWith(shader, [&] {
                renderer->render(vao);
            });
        });
    }
private:
    ShaderProgram shader;

    VAO vao;

    VBO vbo;

    float lines = 10,
        spacing = 0.5;
};

#endif
