#ifndef OPENGL_MSAT_SKYBOX_HPP
#define OPENGL_MSAT_SKYBOX_HPP

#include "cubemap.hpp"
#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/rendering/renderer.hpp"
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

        projection.perspective();

        shader = ShaderProgram();
        shader.setSource(ShaderStage::Vertex, skyboxVert);
        shader.setSource(ShaderStage::Fragment, skyboxFrag);
        shader.compile();

        Object3D cube(Cube(Vec3(-1.0), Vec3(1.0)));

        vao = VAO();
        vbo = VBO();
        vbo.setVertices(cube.getVerticesFlattened(attributes));
        vao.associate(vbo, attributes);
    }

    void render(Renderer* renderer)
    {
        RenderState state;
        state.disable(RenderOption::DepthTesting);
        renderer->swapState(state, [&](Renderer* renderer) {

            shader.uniform(projection);
            shader.uniform("skybox", 0);
            shader.uniform("view", glm::mat4(glm::mat3(projection.getView())));
            shader.uniform("projection", projection.getProjection());

            Context::safeWith(shader, [&] {
                renderer->render(vao);
            });
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
