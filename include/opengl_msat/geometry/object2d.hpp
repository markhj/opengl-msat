#ifndef OPENGL_MSAT_OBJECT2D_HPP
#define OPENGL_MSAT_OBJECT2D_HPP

#include <iostream>
#include "object_wrapper.hpp"
#include "opengl_msat/traits/handles_attributes.hpp"

/**
 * 2D object
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/geometry/object-xd/
 *
 * @todo Implement Object2D -- Currently just a placeholder
 */
class Object2D :
        public HandlesAttributes,
        public ObjectWrapper<VertexElement2D, Vec2> {
public:
    /*
     * @todo Implement getVertices
     */
    std::vector<VertexElement2D> getVertices() override
    {
        return {};
    }

    /*
     * @todo Implement getVerticesFlattened
     */
    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override
    {
        return {};
    }
};

#endif
