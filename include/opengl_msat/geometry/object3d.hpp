#ifndef OPENGL_MSAT_OBJECT3D_HPP
#define OPENGL_MSAT_OBJECT3D_HPP

#include <iostream>
#include "object_wrapper.hpp"
#include "opengl_msat/traits/handles_attributes.hpp"

class Object3D :
        public HandlesAttributes,
        public ObjectWrapper<VertexElement3D, Vec3> {
public:
    std::vector<VertexElement3D> getVertices() override
    {
        std::vector<VertexElement3D> list;
        for (VertexElement3D v : vertices) {
            v.position.x += translation.x;
            v.position.y += translation.y;
            v.position.z += translation.z;
            list.push_back(v);
        }
        return list;
    }

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override
    {
        return flattenVertices3D(getVertices(), attributes);
    }
};

#endif
