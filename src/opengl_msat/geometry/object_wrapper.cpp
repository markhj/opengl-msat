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

//template<typename VertexElementXD>
//std::vector<GLfloat> ObjectWrapper<VertexElementXD>::getVerticesFlattened(std::vector<VertexAttribute> attributes)
//{
//    std::vector<GLfloat> list = {};
//    for (VertexElementXD vertex : vertices) {
//        for (VertexAttribute attr : attributes) {
//            switch (attr) {
//                case VertexAttribute::Position2D:
//                    list.push_back(vertex.position.x);
//                    list.push_back(vertex.position.y);
//                    break;
//                case VertexAttribute::Position3D:
//                    list.push_back(vertex.position.x);
//                    list.push_back(vertex.position.y);
//                    list.push_back(vertex.position.z);
//                    break;
//                default:
//                    throw std::runtime_error("Missing implementation in ObjectWrapper::getVerticesFlattened");
//            }
//        }
//    }
//    return list;
//}

template class ObjectWrapper<VertexElement2D>;
template class ObjectWrapper<VertexElement3D>;
