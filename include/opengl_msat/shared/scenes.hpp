#ifndef OPENGL_MSAT_SCENES_HPP
#define OPENGL_MSAT_SCENES_HPP

#include "opengl_msat/geometry/object3d.hpp"
#include "opengl_msat/geometry/object_collection.hpp"

class Scene3D :
        public ObjectCollection<Object3D, VertexElement3D> {

};

#endif
