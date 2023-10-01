#ifndef OPENGL_MSAT_OBJECT3D_HPP
#define OPENGL_MSAT_OBJECT3D_HPP

#include <iostream>
#include "object_wrapper.hpp"
#include "opengl_msat/traits/handles_attributes.hpp"

class Object3D :
        public HandlesAttributes,
        public ObjectWrapper<VertexElement3D, Vec3> {
public:
    std::vector<VertexElement3D> getVertices() override;

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override;

};

#endif
