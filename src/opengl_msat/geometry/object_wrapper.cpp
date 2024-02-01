#include "opengl_msat/geometry/object_wrapper.hpp"

template <typename VertexElementXD, typename VecX>
void ObjectWrapper<VertexElementXD, VecX>::add(
        std::vector<VertexElementXD> elements)
{
    vertices.insert(vertices.end(), elements.begin(), elements.end());
}

template<typename VertexElementXD, typename VecX>
ObjectWrapper<VertexElementXD, VecX>& ObjectWrapper<VertexElementXD, VecX>::colorize(Color color)
{
    for (size_t i = 0; i < vertices.size(); i++) {
        vertices[i].color = color;
    }
    return *this;
}

template<typename VertexElementXD, typename VecX>
ObjectWrapper<VertexElementXD, VecX>& ObjectWrapper<VertexElementXD, VecX>::colorize(Coloring coloring)
{
    return *this;
}

template class ObjectWrapper<VertexElement2D, Vec2>;
template class ObjectWrapper<VertexElement3D, Vec3>;
