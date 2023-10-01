#include "opengl_msat/geometry/object_collection.hpp"
#include "opengl_msat/geometry/object3d.hpp"
#include "opengl_msat/geometry/object2d.hpp"

template<typename ObjectXD, typename VertexElementXD>
std::vector<VertexElementXD> ObjectCollection<ObjectXD, VertexElementXD>::getVertices()
{
    std::vector<VertexElementXD> list;
    for (ObjectXD* obj : objects) {
        std::vector<VertexElementXD> vs = obj->getVertices();
        list.insert(list.end(), vs.begin(), vs.end());
    }
    return list;
}

template<typename ObjectXD, typename VertexElementXD>
std::vector<GLfloat>
ObjectCollection<ObjectXD, VertexElementXD>::getVerticesFlattened(std::vector<VertexAttribute> attributes)
{
    std::vector<GLfloat> list;
    for (ObjectXD* obj : objects) {
        std::vector<GLfloat> vs = obj->getVerticesFlattened(attributes);
        list.insert(list.end(), vs.begin(), vs.end());
    }
    return list;
}

template<typename ObjectXD, typename VertexElementXD>
void ObjectCollection<ObjectXD, VertexElementXD>::add(ObjectXD *obj)
{
    indices.insert(std::make_pair(obj, currentIndex));
    objects.push_back(obj);

    currentIndex += obj->getVertices().size();
}

template<typename ObjectXD, typename VertexElementXD>
std::optional<unsigned int> ObjectCollection<ObjectXD, VertexElementXD>::getIndex(ObjectXD *obj)
{
    std::optional<unsigned int> result;
    auto f = indices.find(obj);
    if (f != indices.end()) {
        result = f->second;
    }
    return result;
}

template<typename ObjectXD, typename VertexElementXD>
void ObjectCollection<ObjectXD, VertexElementXD>::add(std::vector<ObjectXD *> objs)
{
    for (ObjectXD *obj : objs) {
        add(obj);
    }
}

template<typename ObjectXD, typename VertexElementXD>
std::vector<ObjectXD *> ObjectCollection<ObjectXD, VertexElementXD>::getObjects()
{
    return objects;
}

template class ObjectCollection<Object2D, VertexElement2D>;
template class ObjectCollection<Object3D, VertexElement3D>;
