#include "opengl_msat/geometry/shape.hpp"

std::vector<GLfloat> Shape::getVerticesFlattened(const std::vector<VertexAttribute>& attributes)
{
    reset();
    construct();

    std::vector<GLfloat> list;

    for (VertexElement3D vertex : vertices) {

        list.push_back(vertex.position.x);
        list.push_back(vertex.position.y);
        list.push_back(vertex.position.z);

        if (vertex.normal.has_value()) {
            list.push_back(vertex.normal.value().r);
            list.push_back(vertex.normal.value().g);
            list.push_back(vertex.normal.value().b);
        } else {
            list.push_back(0.0);
            list.push_back(0.0);
            list.push_back(0.0);
        }

        list.push_back(vertex.color.r);
        list.push_back(vertex.color.g);
        list.push_back(vertex.color.b);
    }

    return list;
}

void Shape::addVertex(VertexElement3D vertex)
{
    vertices.push_back(vertex);
}

std::vector<VertexElement3D> Shape::getVertices()
{
    reset();
    construct();

    return vertices;
}

void Shape::reset()
{
    vertices.clear();
}

void Shape::addVertices(std::vector<VertexElement3D> elements)
{
    vertices.insert(vertices.end(), elements.begin(), elements.end());
}
