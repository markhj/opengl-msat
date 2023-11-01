#include "opengl_msat/tools/grid.hpp"

Grid::Grid(Window* window, Camera* camera)
    : projection(Projection(window, camera))
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
        float spaceToCenter = center && x == 0.0 ? spacing : 0.0;

        vertices.insert(vertices.end(), {
            // Z-axis
            x, 0.0, hsize, 1.0, 1.0, 1.0,
            x, 0.0, spaceToCenter, 1.0, 1.0, 1.0,
            x, 0.0, -hsize, 1.0, 1.0, 1.0,
            x, 0.0, -spaceToCenter, 1.0, 1.0, 1.0,

            // X-axis
            hsize, 0.0, x, 1.0, 1.0, 1.0,
            spaceToCenter, 0.0, x, 1.0, 1.0, 1.0,
            -hsize, 0.0, x, 1.0, 1.0, 1.0,
            -spaceToCenter, 0.0, x, 1.0, 1.0, 1.0
        });

        x += spacing;
    }

    if (center) {
        float axisSize = spacing - centerMargin;

        // X-axis (red)
        vertices.insert(vertices.end(), { axisSize, 0.0, 0.0, 1.0, 0.0, 0.0 });
        vertices.insert(vertices.end(), { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 });

        // Y-axis (green)
        vertices.insert(vertices.end(), { 0.0, axisSize, 0.0, 0.0, 1.0, 0.0 });
        vertices.insert(vertices.end(), { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 });

        // Z-axis (blue)
        vertices.insert(vertices.end(), { 0.0, 0.0, axisSize, 0.0, 0.0, 1.0 });
        vertices.insert(vertices.end(), { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 });
    }

    vbo.setVertices(vertices);
}

void Grid::render(Renderer *renderer)
{
    RenderState state;
    state.enable(RenderOption::DepthTesting);
    state.settings.lineSize = lineWidth;

    renderer->swapState(state, [&](Renderer* renderer) {
        shader.uniform(projection);

        Context::safeWith(shader, [&] {
            renderer->render(vao, DrawMode::Lines);
        });
    });
}
