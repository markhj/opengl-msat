#include "opengl_msat/types/vertex_types.hpp"

GLenum getVertexAttributeDataType(VertexAttribute attr)
{
    return GL_FLOAT;
}

std::string getVertexAttributeShaderType(VertexAttribute attr)
{
    std::string size = std::to_string(getVertexAttributeSize(attr));

    switch (attr) {
        case VertexAttribute::MaterialId:
            return "float";
        default:
            return "vec" + size;
    }
}

std::string getVertexAttributeShaderPrefix(VertexAttribute attr)
{
    switch (attr) {
        case VertexAttribute::MaterialId:
            return "flat";
        default:
            return "";
    }
}

unsigned int getVertexAttributeSize(VertexAttribute attr)
{
    switch (attr) {
        case VertexAttribute::ColorRGBA:
            return 4;
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
        case VertexAttribute::MaterialId:
            return 1;
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
        case VertexAttribute::ColorRGBA:
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
        case VertexAttribute::MaterialId:
            return "materialId";
        default:
            throw std::runtime_error("OpenGL MSAT: Missing implementation in getVertexAttributeSize");
    }
}
