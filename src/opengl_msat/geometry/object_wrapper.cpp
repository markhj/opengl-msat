#include "opengl_msat/geometry/object_wrapper.hpp"

template <typename VertexElementXD>
void ObjectWrapper<VertexElementXD>::add(
        std::vector<VertexElementXD> elements)
{
    vertices.insert(vertices.end(), elements.begin(), elements.end());
}

template<typename VertexElementXD>
std::vector<VertexElementXD> ObjectWrapper<VertexElementXD>::getVertices()
{
    return vertices;
}

template class ObjectWrapper<VertexElement2D>;
template class ObjectWrapper<VertexElement3D>;
