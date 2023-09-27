#ifndef OPENGL_MSAT_RECTANGLE_HPP
#define OPENGL_MSAT_RECTANGLE_HPP

#include <utility>

#include "shape.hpp"
#include "vectors.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Vec3 a, Vec3 b) : a(std::move(a)), b(std::move(b)) { }

    void construct() override;
private:
    Vec3 a, b;
};

#endif
