#include "opengl_msat/geometry/object3d.hpp"

std::vector<VertexElement3D> Object3D::getVertices()
{
    std::vector<VertexElement3D> list;
    for (VertexElement3D v : vertices) {
        v.position.x += translation.x;
        v.position.y += translation.y;
        v.position.z += translation.z;
        list.push_back(v);
    }
    return list;
}

std::vector<GLfloat> Object3D::getVerticesFlattened(std::vector<VertexAttribute> attributes)
{
    return flattenVertices3D(getVertices(), attributes);
}
