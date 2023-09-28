#ifndef OPENGL_MSAT_SHAPE_HPP
#define OPENGL_MSAT_SHAPE_HPP

#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/shared/vertex_types.hpp"

class Shape {
public:
    virtual void construct() = 0;

    std::vector<GLfloat> getVerticesFlattened(const std::vector<VertexAttribute>& attributes);

    std::vector<VertexElement> getVertices();

protected:
    void addVertex(VertexElement vertex);

    void addVertices(std::vector<VertexElement> elements);

    void reset();

private:
    std::vector<VertexElement> vertices;
};

#endif