#ifndef OPENGL_MSAT_SHAPE_HPP
#define OPENGL_MSAT_SHAPE_HPP

#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/shared/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"
#include "object3d.hpp"

class Shape3D :
        public ExportsVertices<VertexElement3D> {
public:
    virtual void construct() = 0;

    std::vector<GLfloat> getVerticesFlattened(const std::vector<VertexAttribute> attributes) override;

    std::vector<VertexElement3D> getVertices() override;

    Object3D toObject();

    operator Object3D() {
        return toObject();
    }

protected:
    void addVertex(VertexElement3D vertex);

    void addVertices(std::vector<VertexElement3D> elements);

    void reset();

private:
    std::vector<VertexElement3D> vertices;
};

#endif
