#ifndef OPENGL_MSAT_OBJECT_COLLECTION_HPP
#define OPENGL_MSAT_OBJECT_COLLECTION_HPP

#include <map>
#include "opengl_msat/contracts/exports_vertices.hpp"

template <typename ObjectXD, typename VertexElementXD>
class ObjectCollection :
        public ExportsVertices<VertexElementXD> {
public:
    std::vector<VertexElementXD> getVertices() override;

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override;

    void add(ObjectXD* obj);

    void add(std::vector<ObjectXD*> objs);

    std::optional<unsigned int> getIndex(ObjectXD* obj);

    std::vector<ObjectXD*> getObjects();

private:
    std::vector<ObjectXD*> objects;

    std::map<ObjectXD*, unsigned int> indices;

    unsigned int currentIndex = 0;

};

#endif
