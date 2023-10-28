#ifndef OPENGL_MSAT_SCENES_HPP
#define OPENGL_MSAT_SCENES_HPP

#include "opengl_msat/geometry/object2d.hpp"
#include "opengl_msat/geometry/object3d.hpp"
#include "opengl_msat/geometry/object_collection.hpp"

/**
 * 2D scene
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/render/scene-management/
 */
class Scene2D :
        public ObjectCollection<Object2D, VertexElement2D> {
public:
    explicit Scene2D(const std::vector<Object2D*>& objects);

};

/**
 * 3D scene
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/render/scene-management/
 */
class Scene3D :
        public ObjectCollection<Object3D, VertexElement3D> {
public:
    explicit Scene3D(const std::vector<Object3D*>& objects);

};

#endif
