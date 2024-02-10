#ifndef OPENGL_MSAT_OBJECT_COLLECTION_HPP
#define OPENGL_MSAT_OBJECT_COLLECTION_HPP

#include <map>
#include "opengl_msat/contracts/exports_vertices.hpp"
#include "object3d.hpp"
#include "object2d.hpp"

/**
 * Object collection
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/geometry/object-collection/
 */
template <typename ObjectXD, typename VertexElementXD>
class ObjectCollection :
        public ExportsVertices<VertexElementXD> {
public:
    std::vector<VertexElementXD> getVertices() override;

    std::vector<GLfloat> getVerticesFlattened(const std::vector<VertexAttribute>& attributes) override;

    void add(ObjectXD* obj);

    void add(std::vector<ObjectXD*> objs);

    std::optional<unsigned int> getVertexIndex(ObjectXD* obj);

    std::vector<ObjectXD*> getObjects();

private:
    std::vector<ObjectXD*> objects;

    std::map<ObjectXD*, unsigned int> indices;

    unsigned int currentIndex = 0;

};

template class ObjectCollection<Object3D, VertexElement3D>;
template class ObjectCollection<Object2D, VertexElement2D>;

#endif
