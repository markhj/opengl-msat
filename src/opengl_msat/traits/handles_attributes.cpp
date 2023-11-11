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

void optional2DVector(std::vector<GLfloat>* list, std::optional<Vec2> value)
{
    if (value.has_value()) {
        list->insert(list->end(), { value.value().x, value.value().y });
    } else {
        list->insert(list->end(), { 0.0, 0.0 });
    }
}

void optional3DVector(std::vector<GLfloat>* list, std::optional<Vec3> value)
{
    if (value.has_value()) {
        list->insert(list->end(), { value.value().x, value.value().y, value.value().z });
    } else {
        list->insert(list->end(), { 0.0, 0.0, 0.0 });
    }
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
                case VertexAttribute::TextureCoord:
                    optional2DVector(&list, vertex.textureCoords);
                    break;
                case VertexAttribute::MaterialId:
                    list.push_back(vertex.materialId.has_value() ? vertex.materialId.value() : -1);
                    break;
                case VertexAttribute::ColorRGB:
                    list.insert(list.end(), {vertex.color.r, vertex.color.g, vertex.color.b});
                    break;
                case VertexAttribute::Normal2D:
                    optional2DVector(&list, vertex.normal);
                    break;
                case VertexAttribute::Tangent2D:
                    optional2DVector(&list, vertex.tangent);
                    break;
                case VertexAttribute::Bitangent2D:
                    optional2DVector(&list, vertex.bitangent);
                    break;
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
                    optional2DVector(&list, vertex.textureCoords);
                    break;
                case VertexAttribute::MaterialId:
                    list.push_back(vertex.materialId.has_value() ? vertex.materialId.value() : -1);
                    break;
                case VertexAttribute::Normal3D:
                    optional3DVector(&list, vertex.normal);
                    break;
                case VertexAttribute::Tangent3D:
                    optional3DVector(&list, vertex.tangent);
                    break;
                case VertexAttribute::Bitangent3D:
                    optional3DVector(&list, vertex.bitangent);
                    break;
                case VertexAttribute::ColorRGB:
                    list.insert(list.end(), {vertex.color.r, vertex.color.g, vertex.color.b});
                    break;
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
