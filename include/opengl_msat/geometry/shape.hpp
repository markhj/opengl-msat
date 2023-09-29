#ifndef OPENGL_MSAT_SHAPE_HPP
#define OPENGL_MSAT_SHAPE_HPP

#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/shared/vertex_types.hpp"

class Shape {
public:
    virtual void construct() = 0;

    std::vector<GLfloat> getVerticesFlattened(const std::vector<VertexAttribute>& attributes);

    std::vector<VertexElement3D> getVertices();

protected:
    void addVertex(VertexElement3D vertex);

    void addVertices(std::vector<VertexElement3D> elements);

    void reset();

private:
    std::vector<VertexElement3D> vertices;
};

#endif
