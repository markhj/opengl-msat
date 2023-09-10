#ifndef OPENGL_MSAT_RENDER_TYPES_HPP
#define OPENGL_MSAT_RENDER_TYPES_HPP

#include "opengl_msat/common.h"

enum DrawMode {
    Points = GL_POINTS,
    Lines = GL_LINES,
    Triangles = GL_TRIANGLES,
};

struct RenderSettings {
    float pointSize = 1.0;
    float lineSize = 1.0;
};

#endif
