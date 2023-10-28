#include "opengl_msat/vertex/vbo_scene.hpp"

template<typename ObjectCollection, typename VertexElementXD>
unsigned int SceneManagedVBO<ObjectCollection, VertexElementXD>::byteSize()
{
    return vbo.byteSize();
}

template<typename ObjectCollection, tgit ypename VertexElementXD>
unsigned int SceneManagedVBO<ObjectCollection, VertexElementXD>::count()
{
    return vbo.count();
}

template<typename ObjectCollection, typename VertexElementXD>
void SceneManagedVBO<ObjectCollection, VertexElementXD>::upload(std::vector<ObjectXD<VertexElementXD> *> objects)
{
    for (ObjectXD<VertexElementXD>* obj : objects) {
        for (auto v : scene->getObjects()) {
            if (v == obj) {
                std::optional<unsigned int> index = scene->getVertexIndex(v);
                if (index.has_value()) {
                    vbo.substitute(obj->getVerticesFlattened(attributes),
                                   index.value() * getSizeOfAttributes(attributes));
                }
            }
        }
    }
}

template<typename ObjectCollection, typename VertexElementXD>
void SceneManagedVBO<ObjectCollection, VertexElementXD>::upload()
{
    vbo.setVertices(scene->getVerticesFlattened(attributes));
    vbo.upload();
}

template<typename ObjectCollection, typename VertexElementXD>
void SceneManagedVBO<ObjectCollection, VertexElementXD>::doUnbind()
{
    vbo.unbind();
}

template<typename ObjectCollection, typename VertexElementXD>
void SceneManagedVBO<ObjectCollection, VertexElementXD>::doBind()
{
    vbo.bind();
}

template<typename ObjectCollection, typename VertexElementXD>
SceneManagedVBO<ObjectCollection, VertexElementXD>::SceneManagedVBO(ObjectCollection *oc,
                                                                    std::vector<VertexAttribute> attributes)
        : scene(oc), attributes(std::move(attributes)), vbo(VBO())
{

}
