#include "opengl_msat/geometry/shape.hpp"

std::vector<GLfloat> Shape::getVerticesFlattened(const std::vector<VertexAttribute>& attributes)
{
    reset();
    construct();

    std::vector<GLfloat> list;

    for (VertexElement vertex : vertices) {
        list.push_back(vertex.position.x);
        list.push_back(vertex.position.y);
        list.push_back(vertex.position.z);

        list.push_back(vertex.color.r);
        list.push_back(vertex.color.g);
        list.push_back(vertex.color.b);
    }

    return list;
}

void Shape::addVertex(VertexElement vertex)
{
    vertices.push_back(vertex);
}

std::vector<VertexElement> Shape::getVertices()
{
    reset();
    construct();

    return vertices;
}

void Shape::reset()
{
    vertices.clear();
}

void Shape::addVertices(std::vector<VertexElement> elements)
{
    vertices.insert(vertices.end(), elements.begin(), elements.end());
}
