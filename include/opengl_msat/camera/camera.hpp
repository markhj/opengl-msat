#ifndef OPENGL_MSAT_CAMERA_HPP
#define OPENGL_MSAT_CAMERA_HPP

#include "opengl_msat/geometry/vectors.hpp"
#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/window/window.hpp"

/**
 * Camera
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/camera/camera/
 */
class Camera {
public:
    Vec3 position = Vec3(1.0),
        target = Vec3(0.0),
        up = Vec3(0.0, 1.0, 0.0);

    float fov = 45.0,
        zNear = 0.1,
        zFar = 100.0;

};

#endif
