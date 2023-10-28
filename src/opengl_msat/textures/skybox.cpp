#include "opengl_msat/textures/skybox.hpp"



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

Skybox::Skybox(CubeMap *cubemap, Window *window, Camera *camera)
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

void Skybox::render(Renderer *renderer)
{
    RenderState state;
    state.disable(RenderOption::DepthTesting);

    if (!cubemap->boundToUnit.has_value()) {
        warn("Attempting to use cubemap in skybox. But cubemap isn't bound to a texture unit.");
    }

    renderer->swapState(state, [&](Renderer* renderer) {

        shader.uniform(projection);
        shader.uniform("skybox", cubemap->boundToUnit.has_value() ? cubemap->boundToUnit.value() : 0);
        shader.uniform("view", glm::mat4(glm::mat3(projection.getView())));
        shader.uniform("projection", projection.getProjection());

        Context::safeWith(shader, [&] {
            renderer->render(vao);
        });
    });
}
