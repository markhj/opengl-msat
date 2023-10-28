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

/**
 * Screen quad
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/fbo/screen-quad/
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/fbo/screen-quad-fx/
 */
class ScreenQuad : DeveloperMessaging {
public:
    bool grayscale = false;

    bool inverse = false;

    ScreenQuad(Window* window,
               Camera* camera,
               const Vec2& position,
               const Vec2& size,
               Texture2D* texture);

    void render(Renderer* renderer);

private:
    Projection projection;

    ShaderProgram shader;

    RenderState state;

    VAO vao;

    VBO vbo;

    Texture2D* texture;

};

#endif
