#ifndef OPENGL_MSAT_GRID_HPP
#define OPENGL_MSAT_GRID_HPP

#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/context/context.hpp"
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/rendering/renderer.hpp"
#include "service_provider.hpp"

/**
 * Grid
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/tools/grid/
 */
class Grid {
public:
    Grid(Window* window, Camera* camera);

    void refresh();

    void render(Renderer* renderer);

    int lines = 10;

    float spacing = 0.5;

private:
    Projection projection;

    ShaderProgram shader;

    VAO vao;

    VBO vbo;

};

#endif
