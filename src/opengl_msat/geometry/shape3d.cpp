#include "opengl_msat/geometry/shape3d.hpp"

std::vector<GLfloat> Shape3D::getVerticesFlattened(const std::vector<VertexAttribute> attributes)
{
    reset();
    construct();

    return flattenVertices3D(vertices, attributes);
}

void Shape3D::addVertex(VertexElement3D vertex)
{
    vertices.push_back(vertex);
}

std::vector<VertexElement3D> Shape3D::getVertices()
{
    reset();
    construct();

    return vertices;
}

void Shape3D::reset()
{
    vertices.clear();
}

void Shape3D::addVertices(std::vector<VertexElement3D> elements)
{
    vertices.insert(vertices.end(), elements.begin(), elements.end());
}

Object3D Shape3D::toObject()
{
    Object3D wrapper;
    wrapper.add(getVertices());
    return wrapper;
}
