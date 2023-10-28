#ifndef OPENGL_MSAT_UI_HPP
#define OPENGL_MSAT_UI_HPP

#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/vertex/vao.hpp"
#include "opengl_msat/rendering/renderer.hpp"

class UI {
public:
    UI(Window* window, Camera* camera);

    void render(Renderer* renderer);

    void setVertices(std::vector<GLfloat> vertices);

private:
    ShaderProgram shader;

    VAO vao;

    VBO vbo;

    Projection projection;

};

#endif
