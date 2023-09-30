#ifndef OPENGL_MSAT_VBO_SCENE_HPP
#define OPENGL_MSAT_VBO_SCENE_HPP

#include "opengl_msat/vertex/vbo.hpp"
#include "opengl_msat/contracts/vao_associable.hpp"
#include "opengl_msat/shared/scenes.hpp"
#include <type_traits>
#include <utility>

template <typename ObjectCollection>
class SceneManagedVBO : public VAOAssociable {
public:
    explicit SceneManagedVBO(ObjectCollection* oc, std::vector<VertexAttribute> attributes) :
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

template class SceneManagedVBO<Scene2D>;
template class SceneManagedVBO<Scene3D>;

#endif
