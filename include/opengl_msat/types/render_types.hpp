#ifndef OPENGL_MSAT_RENDER_TYPES_HPP
#define OPENGL_MSAT_RENDER_TYPES_HPP

#include "opengl_msat/common.h"

enum DrawMode {
    Points = GL_POINTS,
    Lines = GL_LINES,
    Triangles = GL_TRIANGLES,
};

/**
 * Render options
 *
 * Important: When new items are added below, they should also
 * be added in the RenderState class (shared/renderstate.hpp).
 * Namely under the "defaults" and "mapping" properties.
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/render-options
 */
enum RenderOption {
    DepthTesting,
    FaceCulling,
    StencilTesting,
    Blend,
};

/**
 * Render settings
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/render-settings
 */
struct RenderSettings {
    float pointSize = 1.0;
    float lineSize = 1.0;
};

#endif
