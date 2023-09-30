#ifndef OPENGL_MSAT_OBJECT2D_HPP
#define OPENGL_MSAT_OBJECT2D_HPP

#include <iostream>
#include "object_wrapper.hpp"

/**
 * @todo Implement Object2D -- Currently just a placeholder
 */
class Object2D : public ObjectWrapper<VertexElement2D, Vec2> {
public:
    std::vector<VertexElement2D> getVertices() override
    {
        return {};
    }

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override
    {
        return {};
    }
};

#endif
