#ifndef OPENGL_MSAT_OBJECT3D_HPP
#define OPENGL_MSAT_OBJECT3D_HPP

#include <iostream>
#include "object_wrapper.hpp"
#include "opengl_msat/traits/handles_attributes.hpp"

/**
 * 3D object
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/geometry/object-xd/
 */
class Object3D :
        public HandlesAttributes,
        public ObjectWrapper<VertexElement3D, Vec3> {
public:
    std::vector<VertexElement3D> getVertices() override;

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override;

    /**
     * If you want your application to rely on the use of translations (rather than coordinates)
     * you can enable automatic centering which will ensure that all objects start at (0, 0, 0)
     * and need translation to move somewhere else
     */
    bool autoCenter = false;

};

#endif
