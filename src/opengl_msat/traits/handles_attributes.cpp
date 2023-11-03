#include <iostream>
#include "opengl_msat/traits/handles_attributes.hpp"

unsigned int HandlesAttributes::getSizeOfAttributes(std::vector<VertexAttribute>& attributes) const
{
    unsigned int size = 0;
    for (VertexAttribute attr : attributes) {
        size += getVertexAttributeSize(attr);
    }
    return size;
}

std::vector<GLfloat>
HandlesAttributes::flattenVertices2D(std::vector<VertexElement2D> elements, std::vector<VertexAttribute> attributes)
{
    std::vector<GLfloat> list = {};
    for (VertexElement2D vertex : elements) {
        for (VertexAttribute attr: attributes) {
            switch (attr) {
                case VertexAttribute::Position2D:
                    list.insert(list.end(), {vertex.position.x, vertex.position.y});
                    break;
                case VertexAttribute::ColorRGB:
                    list.insert(list.end(), {vertex.color.r, vertex.color.g, vertex.color.b});
                    break;
                default:
                    std::cout << "WARNING: Implementation missing in HandlesAttributes::flattenVertices2D: "
                              << getVertexAttributeVarName(attr)
                              << std::endl;
            }
        }
    }
    return list;
}

std::vector<GLfloat>
HandlesAttributes::flattenVertices3D(std::vector<VertexElement3D> elements, std::vector<VertexAttribute> attributes)
{
    std::vector<GLfloat> list = {};
    for (VertexElement3D vertex : elements) {
        for (VertexAttribute attr: attributes) {
            switch (attr) {
                case VertexAttribute::Position3D:
                    list.insert(list.end(), {vertex.position.x, vertex.position.y, vertex.position.z});
                    break;
                case VertexAttribute::TextureCoord:
                    if (vertex.textureCoords.has_value()) {
                        Vec2 texCoords = vertex.textureCoords.value();
                        list.insert(list.end(), {texCoords.x, texCoords.y});
                    } else {
                        list.insert(list.end(), {0.0, 0.0});
                    }
                    break;
                case VertexAttribute::MaterialId:
                    if (vertex.materialId.has_value()) {
                        list.push_back(vertex.materialId.value());
                    } else {
                        list.push_back(-1);
                    }
                    break;
                case VertexAttribute::Normal3D:
                    if (vertex.normal.has_value()) {
                        list.insert(list.end(), {vertex.normal.value().x,
                                                 vertex.normal.value().y,
                                                 vertex.normal.value().z});
                    } else {
                        list.insert(list.end(), {0.0, 0.0, 0.0});
                    }
                    break;
                case VertexAttribute::Tangent3D:
                    if (vertex.tangent.has_value()) {
                        list.insert(list.end(), {vertex.tangent.value().x,
                                                 vertex.tangent.value().y,
                                                 vertex.tangent.value().z});
                    } else {
                        list.insert(list.end(), {0.0, 0.0, 0.0});
                    }
                    break;
                case VertexAttribute::Bitangent3D:
                    if (vertex.bitangent.has_value()) {
                        list.insert(list.end(), {vertex.bitangent.value().x,
                                                 vertex.bitangent.value().y,
                                                 vertex.bitangent.value().z});
                    } else {
                        list.insert(list.end(), {0.0, 0.0, 0.0});
                    }
                    break;
                case VertexAttribute::ColorRGB:
                    list.insert(list.end(), {vertex.color.r, vertex.color.g, vertex.color.b});
                    break;
                default:
                    std::cout << "WARNING: Implementation missing in HandlesAttributes::flattenVertices3D: "
                              << getVertexAttributeVarName(attr)
                              << std::endl;
            }
        }
    }
    return list;
}

Vec3 HandlesAttributes::findCenter3D(std::vector<VertexElement3D> elements)
{
    float x = 0.0, y = 0.0, z = 0.0, count = elements.size();

    for (VertexElement3D vertex : elements) {
        x += vertex.position.x;
        y += vertex.position.y;
        z += vertex.position.z;
    }

    return Vec3(x / count, y / count, z / count);
}

Vec2 HandlesAttributes::findCenter2D(std::vector<VertexElement2D> elements)
{
    float x = 0.0, y = 0.0, count = elements.size();

    for (VertexElement2D vertex : elements) {
        x += vertex.position.x;
        y += vertex.position.y;
    }

    return Vec2(x / count, y / count);
}
