#ifndef OPENGL_MSAT_CUBE_HPP
#define OPENGL_MSAT_CUBE_HPP

#include <utility>

#include "shape3d.hpp"

/**
 * Cube
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/geometry/cube/
 */
class Cube : public Shape3D {
public:
    Cube(Vec3 a, Vec3 b) : a(std::move(a)), b(std::move(b)) { }

    explicit Cube(const Vec3& size) :
        a(Vec3(size.x / -2, size.y / -2, size.z / -2)),
        b(Vec3(size.x / 2, size.y / 2, size.z / 2))
    { }

    void construct() override;

private:
    Vec3 a, b;

};

#endif
