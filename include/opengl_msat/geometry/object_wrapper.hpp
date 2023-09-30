#ifndef OPENGL_MSAT_OBJECT_WRAPPER_HPP
#define OPENGL_MSAT_OBJECT_WRAPPER_HPP

#include <vector>
#include "opengl_msat/shared/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"

template <typename VertexElementXD>
class ObjectWrapper :
        public ExportsVertices<VertexElementXD> {
public:
    void add(std::vector<VertexElementXD> elements);

    std::vector<VertexElementXD> getVertices() override;

protected:
    std::vector<VertexElementXD> vertices = {};
};

#endif
