#ifndef OPENGL_MSAT_SCRQUAD_HPP
#define OPENGL_MSAT_SCRQUAD_HPP

#include <vector>
#include "opengl_msat/types/vertex_types.hpp"
#include "opengl_msat/types/projections.hpp"
#include "opengl_msat/shader/vertex_sbldr.hpp"
#include "opengl_msat/shader/shader.hpp"
#include "opengl_msat/vertex/vao.hpp"
#include "renderer.hpp"
#include "opengl_msat/textures/texture2d.hpp"

const char* scrquadFragmentSource = R"(
#version 330 core
out vec4 result;

in vec2 texCoords;

uniform sampler2D tx;

void main()
{
    result = texture(tx, texCoords);
}
)";

class ScreenQuad : DeveloperMessaging {
public:
    ScreenQuad(Window* window,
               Camera* camera,
               const Vec2& position,
               const Vec2& size,
               Texture2D* texture)
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

    void render(Renderer* renderer)
    {
        shader.safeBind();
        shader.uniform(projection);

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

private:
    Projection projection;

    ShaderProgram shader;

    RenderState state;

    VAO vao;

    VBO vbo;

    Texture2D* texture;

};

#endif
