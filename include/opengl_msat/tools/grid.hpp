#ifndef OPENGL_MSAT_GRID_HPP
#define OPENGL_MSAT_GRID_HPP

#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/context/context.hpp"
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/renderer/renderer.hpp"

class Grid {
public:
    Grid();

    void refresh();

    void render(Renderer* renderer);
private:
    ShaderProgram shader;

    VAO vao;

    VBO vbo;

    int lines = 10;

    float spacing = 0.5;
};

#endif
