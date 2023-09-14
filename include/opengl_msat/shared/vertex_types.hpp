#ifndef OPENGL_MSAT_VERTEX_TYPES_HPP
#define OPENGL_MSAT_VERTEX_TYPES_HPP

#include <stdexcept>

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
