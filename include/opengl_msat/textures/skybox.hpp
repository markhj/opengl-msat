#ifndef OPENGL_MSAT_SKYBOX_HPP
#define OPENGL_MSAT_SKYBOX_HPP

#include "cubemap.hpp"
#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/renderer/renderer.hpp"
#include "opengl_msat/geometry/cube.hpp"

const char* skyboxVert = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 texCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position = projection * view * vec4(aPos, 1.0);
    texCoords = aPos;
}
)";

const char* skyboxFrag = R"(
#version 330 core
out vec4 FragColor;

in vec3 texCoords;

//uniform sampler2D skybox;
uniform samplerCube skybox;

void main()
{
    FragColor = texture(skybox, texCoords);
}
)";

class Skybox {
public:
    explicit Skybox(CubeMap* cubemap, Window* window, Camera* camera)
        : cubemap(cubemap),
        projection(Projection(window, camera))
    {
        std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D };

        shader = ShaderProgram();
        shader.setSource(ShaderStage::Vertex, skyboxVert);
        shader.setSource(ShaderStage::Fragment, skyboxFrag);
        shader.compile();

//        projection.orthographic();

        Object3D cube(Cube(Vec3(-0.25, 0.0, -0.25), Vec3(0.25, 0.5, 0.25)));

        vao = VAO();
        vbo = VBO();
        vbo.setVertices(cube.getVerticesFlattened(attributes));
        vao.associate(vbo, attributes);
    }

    void render(Renderer* renderer)
    {
        RenderState state;
//        state.enable(RenderOption::DepthTesting);
//        state.disable(RenderOption::DepthTesting);
//        glDisable(GL_CULL_FACE);
        renderer->swapState(state, [&](Renderer* renderer) {
//            shader.uniform(projection);
//            shader.uniform("view", glm::mat4(glm::mat3(projection.getView())));
//            shader.uniform("skybox", 0);

//            glDepthMask(GL_TRUE);
            Context::safeWith(shader, [&] {
                renderer->render(vao);
            });
//            glDepthMask(GL_FALSE);
        });
    }

private:
    Projection projection;

    CubeMap* cubemap;

    VAO vao;

    VBO vbo;

    ShaderProgram shader;

};

#endif
