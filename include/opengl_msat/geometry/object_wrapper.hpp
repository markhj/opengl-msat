#ifndef OPENGL_MSAT_OBJECT_WRAPPER_HPP
#define OPENGL_MSAT_OBJECT_WRAPPER_HPP

#include <utility>
#include <vector>
#include "opengl_msat/types/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"

/**
 * Object XD
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/geometry/object-xd/
 */
template <typename VertexElementXD>
class ObjectXD : public ExportsVertices<VertexElementXD> {

};

/**
 * Object wrapper
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/geometry/object-xd/
 */
template <typename VertexElementXD, typename VecX>
class ObjectWrapper : public ObjectXD<VertexElementXD> {
public:
    void add(std::vector<VertexElementXD> elements);

    ObjectWrapper& colorize(Color color);

    VecX translate = VecX(0.0);

    float scale = 1.0;

protected:
    std::vector<VertexElementXD> vertices = {};
};

#endif
