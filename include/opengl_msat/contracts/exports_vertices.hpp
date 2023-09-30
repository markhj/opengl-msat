#ifndef OPENGL_MSAT_EXPORTS_VERTICES_HPP
#define OPENGL_MSAT_EXPORTS_VERTICES_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/shared/vertex_types.hpp"
#include <vector>

template <typename VertexElementXD>
class ExportsVertices {
public:
    virtual std::vector<VertexElementXD> getVertices() = 0;

    virtual std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) = 0;
};

#endif
