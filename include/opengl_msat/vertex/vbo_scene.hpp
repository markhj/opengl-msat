#ifndef OPENGL_MSAT_VBO_SCENE_HPP
#define OPENGL_MSAT_VBO_SCENE_HPP

#include "opengl_msat/vertex/vbo.hpp"
#include "opengl_msat/contracts/vao_associable.hpp"
#include "opengl_msat/shared/scenes.hpp"
#include "opengl_msat/traits/handles_attributes.hpp"

template <typename ObjectCollection, typename VertexElementXD>
class SceneManagedVBO :
        public VAOAssociable,
        public HandlesAttributes {
public:
    SceneManagedVBO(ObjectCollection* oc, std::vector<VertexAttribute> attributes) :
        scene(oc),
        attributes(std::move(attributes)),
        vbo(VBO())
    {

    }

    void doBind() override
    {
        vbo.bind();
    }

    void doUnbind() override
    {
        vbo.unbind();
    }

    void upload() override
    {
        vbo.setVertices(scene->getVerticesFlattened(attributes));
        vbo.upload();
    };

    void upload(std::vector<ObjectXD<VertexElementXD>*> objects)
    {
        for (ObjectXD<VertexElementXD>* obj : objects) {
            for (auto v : scene->getObjects()) {
                if (v == obj) {
                    std::optional<unsigned int> index = scene->getIndex(v);
                    if (index.has_value()) {
                        vbo.substitute(obj->getVerticesFlattened(attributes),
                                       index.value() * getSizeOfAttributes(attributes));
                    }
                }
            }
        }
    }

    unsigned int count() override
    {
        return vbo.count();
    };

    unsigned int byteSize() override
    {
        return vbo.byteSize();
    };

protected:
    ObjectCollection* scene;

    std::vector<VertexAttribute> attributes;

    VBO vbo;
};

#endif
