#ifndef OPENGL_MSAT_OBJECT_WRAPPER_HPP
#define OPENGL_MSAT_OBJECT_WRAPPER_HPP

#include <utility>
#include <vector>
#include "opengl_msat/shared/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"

template <typename VertexElementXD>
class ObjectXD : public ExportsVertices<VertexElementXD> {

};

template <typename VertexElementXD, typename VecX>
class ObjectWrapper : public ObjectXD<VertexElementXD> {
public:
    void add(std::vector<VertexElementXD> elements);

    ObjectWrapper& colorize(Color color);

    VecX translate = VecX(0.0), rotate = VecX(0.0);

    float scale = 1.0;

protected:
    std::vector<VertexElementXD> vertices = {};
};

#endif
