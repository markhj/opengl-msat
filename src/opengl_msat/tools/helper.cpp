#include "opengl_msat/tools/helper.hpp"

Helper::Helper() : vao(VAO()), vbo(VBO()), shader(ShaderProgram())
{
    std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D, VertexAttribute::ColorRGB };

    vbo.setVertices({
        0.0, 0.0, 0.0,      0.0, 0.0, 0.0,
    });
    vao.associate(vbo, attributes);

    // .setProjection(ProjectionType::Perspective)
    shader.fromBuilder(VertexShaderBuilder(attributes));
    shader.fromBuilder(FragmentShaderBuilder(attributes));
    shader.compile();
}

void Helper::render(Renderer *renderer)
{
    RenderState state;
    state.enable(RenderOption::DepthTesting);
    state.applyAll();

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

    renderer->swapState(state, [&](Renderer* renderer) {
        RenderSettings newSettings {
            .pointSize = 10.0,
            .lineSize = 3.0
        };

        renderer->swapSettings(newSettings, [&](Renderer* renderer) {
            shader.uniform(renderer->getCamera());

            Context::safeWith(shader, [&] {
                renderer->render(vao, DrawMode::Points, 0, points);
                renderer->render(vao, DrawMode::Lines, points, lines * 2);
            });
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
