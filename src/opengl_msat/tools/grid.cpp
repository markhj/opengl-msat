#include "opengl_msat/tools/grid.hpp"

Grid::Grid()
{
    std::vector<VertexAttribute> attributes = {
            VertexAttribute::Position3D,
            VertexAttribute::ColorRGB,
    };

    refresh();

    vao.associate(vbo, attributes);

    VertexShaderBuilder vsb(attributes);
    FragmentShaderBuilder fsb(attributes);

//    vsb.setProjection(ProjectionType::Perspective);

    shader = ShaderProgram();
    shader.fromBuilder(vsb);
    shader.fromBuilder(fsb);
    shader.compile();
}

void Grid::refresh()
{
    std::vector<GLfloat> vertices = {};

    float hsize = floor(spacing * lines) / 2;
    float x = -hsize;
    while (x <= hsize) {

        vertices.push_back(x);
        vertices.push_back(0.0);
        vertices.push_back(hsize);

        vertices.push_back(1.0);
        vertices.push_back(1.0);
        vertices.push_back(1.0);

        vertices.push_back(x);
        vertices.push_back(0.0);
        vertices.push_back(-hsize);

        vertices.push_back(1.0);
        vertices.push_back(1.0);
        vertices.push_back(1.0);

        x += spacing;
    }

    float z = -hsize;
    while (z <= hsize) {

        vertices.push_back(hsize);
        vertices.push_back(0.0);
        vertices.push_back(z);

        vertices.push_back(1.0);
        vertices.push_back(1.0);
        vertices.push_back(1.0);

        vertices.push_back(-hsize);
        vertices.push_back(0.0);
        vertices.push_back(z);

        vertices.push_back(1.0);
        vertices.push_back(1.0);
        vertices.push_back(1.0);

        z += spacing;
    }

    vbo.setVertices(vertices);
}

void Grid::render(Renderer *renderer)
{
    RenderState state;
    state.enable(RenderOption::DepthTesting);

    renderer->swapState(state, [&](Renderer* renderer) {
        RenderSettings newSettings {
            .lineSize = 2.0
        };

        renderer->swapSettings(newSettings, [&](Renderer* renderer) {
            shader.uniform(renderer->getCamera());

            Context::safeWith(shader, [&] {
                renderer->render(vao, DrawMode::Lines);
            });
        });
    });
}
