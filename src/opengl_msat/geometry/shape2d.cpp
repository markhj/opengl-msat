#include "opengl_msat/geometry/shape2d.hpp"

std::vector<GLfloat> Shape2D::getVerticesFlattened(const std::vector<VertexAttribute> attributes)
{
    reset();
    construct();

    std::vector<GLfloat> list;

    for (VertexElement2D vertex : vertices) {

        list.push_back(vertex.position.x);
        list.push_back(vertex.position.y);

        if (vertex.normal.has_value()) {
            list.push_back(vertex.normal.value().r);
            list.push_back(vertex.normal.value().g);
        } else {
            list.push_back(0.0);
            list.push_back(0.0);
        }

        list.push_back(vertex.color.r);
        list.push_back(vertex.color.g);
        list.push_back(vertex.color.b);
    }

    return list;
}

std::vector<VertexElement2D> Shape2D::getVertices()
{
    reset();
    construct();

    return vertices;
}

Object2D Shape2D::toObject()
{
    Object2D wrapper;
    wrapper.add(getVertices());
    return wrapper;
}

void Shape2D::addVertex(VertexElement2D vertex)
{
    vertices.push_back(vertex);
}

void Shape2D::addVertices(std::vector<VertexElement2D> elements)
{
    vertices.insert(vertices.end(), elements.begin(), elements.end());
}

void Shape2D::reset()
{
    vertices.clear();
}
