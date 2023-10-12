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

/**
 * @todo Implement flattenVertices2D
 */
std::vector<GLfloat>
HandlesAttributes::flattenVertices2D(std::vector<VertexElement3D> elements, std::vector<VertexAttribute> attributes)
{
    return {};
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

Vec2 HandlesAttributes::findCenter2D(std::vector<VertexElement3D> elements)
{
    return Vec2(0);
}
