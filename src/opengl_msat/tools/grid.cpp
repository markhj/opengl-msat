#include "opengl_msat/tools/grid.hpp"

Grid::Grid(Factory* factory) : projection(factory->createProjection())
{
    std::vector<VertexAttribute> attributes = {
            VertexAttribute::Position3D,
            VertexAttribute::ColorRGB,
    };

    refresh();

    vao.associate(vbo, attributes);

    projection.perspective();

    VertexShaderBuilder vsb(attributes);
    FragmentShaderBuilder fsb(attributes);

    vsb.projection = &projection;

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
    state.settings.lineSize = 4.0;

    renderer->swapState(state, [&](Renderer* renderer) {
        shader.uniform(projection);

        Context::safeWith(shader, [&] {
            renderer->render(vao, DrawMode::Lines);
        });
    });
}
