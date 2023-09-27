#ifndef OPENGL_MSAT_CUBE_HPP
#define OPENGL_MSAT_CUBE_HPP

#include <utility>

#include "shape.hpp"

class Cube : public Shape {
public:
    Cube(Vec3 a, Vec3 b) : a(std::move(a)), b(std::move(b)) { }

    void construct() override;

private:
    Vec3 a, b;

};

#endif
