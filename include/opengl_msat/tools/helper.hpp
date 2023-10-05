#ifndef OPENGL_MSAT_HELPER_HPP
#define OPENGL_MSAT_HELPER_HPP

#include "opengl_msat/renderer/renderer.hpp"
#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/shader/vertex_sbldr.hpp"
#include "opengl_msat/shader/fragment_sbldr.hpp"

class Helper {
public:
    Helper();

    void render(Renderer* renderer);

    Helper& track(PointLight* pointLight);

    Helper& track(SpotLight* spotLight);

private:
    std::vector<PointLight*> pointLights;

    std::vector<SpotLight*> spotLights;

    VAO vao;

    VBO vbo;

    ShaderProgram shader;

};

#endif
