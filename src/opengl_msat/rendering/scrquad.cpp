#include "opengl_msat/rendering/scrquad.hpp"

const char* scrquadFragmentSource = R"(
#version 330 core
out vec4 result;

in vec2 texCoords;

uniform sampler2D tx;

uniform bool grayscale;
uniform bool inverse;

void main()
{
    result = texture(tx, texCoords);

    if (grayscale) {
        float luminance = dot(result.rgb, vec3(0.299, 0.587, 0.114));
        result = vec4(luminance, luminance, luminance, 1.0);
    }

    if (inverse) {
        result = 1.0 - result;
    }
}
)";

ScreenQuad::ScreenQuad(Window *window, Camera *camera, const Vec2 &position, const Vec2 &size, Texture2D *texture)
    : projection(Projection(window, camera)),
      shader(ShaderProgram()),
      state(RenderState()),
      texture(texture)
{
    std::vector<VertexAttribute> attrs = { VertexAttribute::Position3D, VertexAttribute::TextureCoord };

    projection.orthographic();

    VertexShaderBuilder vsb(attrs);
    vsb.projection = &projection;

    shader.setSource(ShaderStage::Fragment, scrquadFragmentSource);
    shader.fromBuilder(vsb);
    shader.compile();

    Vec2 bl(position.x, position.y),
            br(position.x + size.x, position.y),
            tl(position.x, position.y + size.y),
            tr(position.x + size.x, position.y + size.y);

    vbo.setVertices({
                            bl.x, bl.y, 0.0,    0.0, 0.0,
                            br.x, br.y, 0.0,    1.0, 0.0,
                            tr.x, tr.y, 0.0,    1.0, 1.0,

                            bl.x, bl.y, 0.0,    0.0, 0.0,
                            tr.x, tr.y, 0.0,    1.0, 1.0,
                            tl.x, tl.y, 0.0,    0.0, 1.0,
                    });
    vao.associate(vbo, attrs);

    state.disable(RenderOption::DepthTesting);
}

void ScreenQuad::render(Renderer *renderer)
{
    shader.safeBind();
    shader.uniform(projection);
    shader.uniform("grayscale", grayscale);
    shader.uniform("inverse", inverse);

    if (texture->boundToUnit.has_value()) {
        shader.uniform("tx", texture->boundToUnit.value());
    } else {
        shader.uniform("tx", 0);
        warn("The texture attached to the screen quad is not bound to a texture unit.");
    }

    renderer->swapState(state, [&](Renderer* renderer) {
        renderer->render(vao);
    });

    shader.safeUnbind();
}
