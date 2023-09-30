#ifndef OPENGL_MSAT_OBJECT_WRAPPER_HPP
#define OPENGL_MSAT_OBJECT_WRAPPER_HPP

#include <utility>
#include <vector>
#include "opengl_msat/shared/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"

template <typename VertexElementXD, typename VecX>
class ObjectWrapper :
        public ExportsVertices<VertexElementXD> {
public:
    void add(std::vector<VertexElementXD> elements);

    ObjectWrapper& translate(Vec3 value);

protected:
    std::vector<VertexElementXD> vertices = {};

    Vec3 translation = Vec3(0.0);
};

#endif
