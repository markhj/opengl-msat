#include "opengl_msat/ui/ui.hpp"


UI::UI(Window *window, Camera *camera)
    : vao(VAO()), vbo(VBO()), shader(ShaderProgram()), projection(Projection(window, camera))
{
    std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D,
                                                VertexAttribute::ColorRGBA };

    vbo.setVertices({});
    vao.associate(vbo, attributes);

    projection.orthographic();

    VertexShaderBuilder hudVsb(attributes);
    hudVsb.projection = &projection;

    FragmentShaderBuilder fsb(attributes);

    shader.fromBuilder(hudVsb);
    shader.fromBuilder(fsb);
    shader.compile();
}

void UI::render(Renderer *renderer)
{
    Camera* camera = renderer->getCamera();

    float currentNear = camera->zNear,
            currentFar = camera->zFar;

    RenderState state;
    state.enable(RenderOption::DepthTesting);
    state.enable(RenderOption::Blend);
    state.setBlendingFunction();

    camera->zNear = -1.0;
    camera->zFar = 1.0;

//        rendering->swapState(state, [&](Renderer* rendering) {
    shader.uniform(projection);
    shader.bind();

    Context::with(shader, [&] {
        renderer->render(vao);
    });
//        });

    camera->zNear = currentNear;
    camera->zFar = currentFar;
}

void UI::setVertices(std::vector<GLfloat> vertices)
{
    vbo.setVertices(vertices);
    vbo.upload();
}
