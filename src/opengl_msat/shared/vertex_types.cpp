#include "opengl_msat/shared/vertex_types.hpp"

unsigned int getVertexAttributeSize(VertexAttribute attr)
{
    switch (attr) {
        case VertexAttribute::Position3D:
        case VertexAttribute::ColorRGB:
        case VertexAttribute::Normal3D:
        case VertexAttribute::Tangent3D:
        case VertexAttribute::Bitangent3D:
            return 3;
        case VertexAttribute::Position2D:
        case VertexAttribute::TextureCoord:
        case VertexAttribute::Normal2D:
        case VertexAttribute::Tangent2D:
        case VertexAttribute::Bitangent2D:
            return 2;
        default:
            throw std::runtime_error("OpenGL MSAT: Missing implementation in getVertexAttributeSize");
    }
}

const char* getVertexAttributeVarName(VertexAttribute attr)
{
    switch (attr) {
        case VertexAttribute::Position3D:
        case VertexAttribute::Position2D:
            return "pos";
        case VertexAttribute::ColorRGB:
            return "color";
        case VertexAttribute::TextureCoord:
            return "texCoords";
        case VertexAttribute::Normal3D:
        case VertexAttribute::Normal2D:
            return "normal";
        case VertexAttribute::Tangent3D:
        case VertexAttribute::Tangent2D:
            return "tangent";
        case VertexAttribute::Bitangent3D:
        case VertexAttribute::Bitangent2D:
            return "bitangent";
        default:
            throw std::runtime_error("OpenGL MSAT: Missing implementation in getVertexAttributeSize");
    }
}
