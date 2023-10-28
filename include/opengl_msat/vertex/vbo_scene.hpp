#ifndef OPENGL_MSAT_VBO_SCENE_HPP
#define OPENGL_MSAT_VBO_SCENE_HPP

#include "opengl_msat/vertex/vbo.hpp"
#include "opengl_msat/contracts/vao_associable.hpp"
#include "opengl_msat/types/scenes.hpp"
#include "opengl_msat/traits/handles_attributes.hpp"

template <typename ObjectCollection, typename VertexElementXD>
class SceneManagedVBO :
        public VAOAssociable,
        public HandlesAttributes {
public:
    SceneManagedVBO(ObjectCollection* oc, std::vector<VertexAttribute> attributes);

    void doBind() override;

    void doUnbind() override;

    void upload() override;

    void upload(std::vector<ObjectXD<VertexElementXD>*> objects);

    unsigned int count() override;

    unsigned int byteSize() override;

protected:
    ObjectCollection* scene;

    std::vector<VertexAttribute> attributes;

    VBO vbo;
};

template class SceneManagedVBO<Scene3D, VertexElement3D>;
template class SceneManagedVBO<Scene2D, VertexElement2D>;

class VBOScene3D : public SceneManagedVBO<Scene3D, VertexElement3D> {
public:
    using SceneManagedVBO::SceneManagedVBO;
};

class VBOScene2D : public SceneManagedVBO<Scene2D, VertexElement2D> {
public:
    using SceneManagedVBO::SceneManagedVBO;
};

#endif
