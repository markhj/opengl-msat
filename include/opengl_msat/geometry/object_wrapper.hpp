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

    ObjectWrapper& translate(VecX value);

    ObjectWrapper& scale(float value);

    ObjectWrapper& rotate(VecX value);

protected:
    std::vector<VertexElementXD> vertices = {};

    VecX translation = VecX(0.0), rotation = VecX(0.0);

    float scaling = 1.0;
};

#endif
