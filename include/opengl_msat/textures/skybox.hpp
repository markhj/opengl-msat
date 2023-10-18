#ifndef OPENGL_MSAT_SKYBOX_HPP
#define OPENGL_MSAT_SKYBOX_HPP

#include "cubemap.hpp"
#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/renderer/renderer.hpp"
#include "opengl_msat/geometry/cube.hpp"

const char* skyboxVert = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 texCoords;

uniform mat4 ortho;

void main()
{
    gl_Position = ortho * vec4(aPos, 1.0);
    texCoords = aTexCoords;
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
    explicit Skybox(CubeMap* cubemap) : cubemap(cubemap)
    {
        std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D };

        shader = ShaderProgram();
        shader.setSource(ShaderStage::Vertex, skyboxVert);
        shader.setSource(ShaderStage::Fragment, skyboxFrag);
        shader.compile();

        Object3D cube(Cube(Vec3(-0.25, 0.0, -0.25), Vec3(0.25, 0.5, 0.25)));

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
//            shader.uniform(renderer->getCamera());

            // We need to create a projection

            Context::safeWith(shader, [&] {
                renderer->render(vao);
            });
        });
    }

private:
    CubeMap* cubemap;

    VAO vao;

    VBO vbo;

    ShaderProgram shader;

};

#endif
