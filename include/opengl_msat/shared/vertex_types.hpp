#ifndef OPENGL_MSAT_VERTEX_TYPES_HPP
#define OPENGL_MSAT_VERTEX_TYPES_HPP

#include <stdexcept>
#include <optional>
#include "opengl_msat/common.h"
#include "opengl_msat/geometry/vectors.hpp"
#include "opengl_msat/types/color.hpp"
#include "opengl_msat/contracts/vertex_element.hpp"

struct VertexElement2D : public VertexElement {
    Vec2 position;
    Color color = Color(1.0, 1.0, 1.0);
    std::optional<Vec2> normal;
};

struct VertexElement3D : public VertexElement {
    Vec3 position;
    Color color = Color(1.0, 1.0, 1.0);
    std::optional<Vec3> normal;
};

enum class VertexAttribute {
    Position2D,
    Position3D,

    MaterialId,

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
GLenum getVertexAttributeDataType(VertexAttribute attr);

#endif
