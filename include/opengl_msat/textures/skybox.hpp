#ifndef OPENGL_MSAT_SKYBOX_HPP
#define OPENGL_MSAT_SKYBOX_HPP

#include "cubemap.hpp"
#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/rendering/renderer.hpp"
#include "opengl_msat/geometry/cube.hpp"

class Skybox : DeveloperMessaging {
public:
    explicit Skybox(CubeMap* cubemap, Window* window, Camera* camera);

    void render(Renderer* renderer);

private:
    Projection projection;

    CubeMap* cubemap;

    VAO vao;

    VBO vbo;

    ShaderProgram shader;

};

#endif
