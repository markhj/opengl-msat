#include "opengl_msat/tools/helper.hpp"

Helper::Helper(Window* window, Camera* camera)
    : vao(VAO()), vbo(VBO()), shader(ShaderProgram()), projection(Projection(window, camera))
{
    std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D, VertexAttribute::ColorRGB };

    vbo.setVertices({
        0.0, 0.0, 0.0,      0.0, 0.0, 0.0,
    });
    vao.associate(vbo, attributes);

    projection.perspective();

    VertexShaderBuilder vsb(attributes);
    vsb.projection = &projection;

    shader.fromBuilder(vsb);
    shader.fromBuilder(FragmentShaderBuilder(attributes));
    shader.compile();
}

void Helper::render(Renderer *renderer)
{

    std::vector<GLfloat> data;

    int points = 0, lines = 0;

    for (PointLight* pointLight : pointLights) {
        Vec3 p = pointLight->position;
        Vec3 c = pointLight->diffuseColor;
        data.insert(data.end(), {p.x, p.y, p.z, c.x, c.y, c.z});
        points++;
    }

    for (SpotLight* light : spotLights) {
        Vec3 p = light->position;
        Vec3 c = light->diffuseColor;
        data.insert(data.end(), {p.x, p.y, p.z, c.x, c.y, c.z});
        points++;
    }

    for (SpotLight* light : spotLights) {
        Vec3 p = light->position;
        Vec3 c = light->diffuseColor;
        data.insert(data.end(), {p.x, p.y, p.z, c.x, c.y, c.z});
        points++;
    }

    for (SpotLight* light : spotLights) {
        glm::vec3 normDir = glm::normalize(light->direction);
        normDir *= 0.3;
        Vec3 p = light->position;
        Vec3 e = p + normDir;
        Vec3 c = light->diffuseColor;
        data.insert(data.end(), {p.x, p.y, p.z, c.x, c.y, c.z, e.x, e.y, e.z, c.x, c.y, c.z});
        lines++;
    }

    vbo.setVertices(data);
    vbo.upload();

    RenderState state;
    state.enable(RenderOption::DepthTesting);
    state.settings.pointSize = 10.0;
    state.settings.lineSize = 3.0;

    renderer->swapState(state, [&](Renderer* renderer) {
        shader.uniform(projection);

        Context::safeWith(shader, [&] {
            renderer->render(vao, DrawMode::Points, 0, points);
            renderer->render(vao, DrawMode::Lines, points, lines * 2);
        });
    });
}

Helper &Helper::track(PointLight *pointLight)
{
    pointLights.push_back(pointLight);
    return *this;
}

Helper &Helper::track(SpotLight *spotLight)
{
    spotLights.push_back(spotLight);
    return *this;
}
