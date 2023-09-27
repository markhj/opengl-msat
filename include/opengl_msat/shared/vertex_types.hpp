#ifndef OPENGL_MSAT_VERTEX_TYPES_HPP
#define OPENGL_MSAT_VERTEX_TYPES_HPP

#include <stdexcept>
#include <optional>
#include "opengl_msat/geometry/vectors.hpp"
#include "opengl_msat/types/color.hpp"

struct VertexElement {
    Vec3 position;
    Color color = Color(1.0, 1.0, 1.0);
};

enum class VertexAttribute {
    Position2D,
    Position3D,

    ColorRGB,

    TextureCoord,

    Normal2D,
    Tangent2D,
    Bitangent2D,

    Normal3D,
    Tangent3D,
    Bitangent3D,
};

unsigned int getVertexAttributeSize(VertexAttribute attr);
const char* getVertexAttributeVarName(VertexAttribute attr);

#endif
