#ifndef OPENGL_MSAT_OBJECT_COLLECTION_HPP
#define OPENGL_MSAT_OBJECT_COLLECTION_HPP

#include "opengl_msat/contracts/exports_vertices.hpp"

template <typename ObjectXD, typename VertexElementXD>
class ObjectCollection :
        public ExportsVertices<VertexElementXD> {
public:
    std::vector<VertexElementXD> getVertices() override;

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override;

    void add(ObjectXD* obj);

    void add(std::vector<ObjectXD*> objs);

private:
    std::vector<ObjectXD*> objects;
};

template<typename ObjectXD, typename VertexElementXD>
void ObjectCollection<ObjectXD, VertexElementXD>::add(std::vector<ObjectXD *> objs)
{
    for (ObjectXD *obj : objs) {
        add(obj);
    }
}

#endif
