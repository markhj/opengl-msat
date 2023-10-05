#ifndef OPENGL_MSAT_HANDLES_ATTRIBUTES_HPP
#define OPENGL_MSAT_HANDLES_ATTRIBUTES_HPP

#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/shared/vertex_types.hpp"

class HandlesAttributes {
protected:
    std::vector<GLfloat> flattenVertices2D(std::vector<VertexElement3D> elements,
                                           std::vector<VertexAttribute> attributes);

    std::vector<GLfloat> flattenVertices3D(std::vector<VertexElement3D> elements,
                                           std::vector<VertexAttribute> attributes);

    Vec3 findCenter3D(std::vector<VertexElement3D> elements);

    Vec2 findCenter2D(std::vector<VertexElement3D> elements);

    unsigned int getSizeOfAttributes(std::vector<VertexAttribute>& attributes) const;

};

#endif
