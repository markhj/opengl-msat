#ifndef OPENGL_MSAT_SHAPE3D_HPP
#define OPENGL_MSAT_SHAPE3D_HPP

#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/types/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"
#include "object3d.hpp"

/**
 * 3D shape
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/geometry/shapes/
 */
class Shape3D :
        public ExportsVertices<VertexElement3D>,
        HandlesAttributes {
public:
    virtual void construct() = 0;

    std::vector<GLfloat> getVerticesFlattened(const std::vector<VertexAttribute>& attributes) override;

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
