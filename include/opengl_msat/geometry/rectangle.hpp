#ifndef OPENGL_MSAT_RECTANGLE_HPP
#define OPENGL_MSAT_RECTANGLE_HPP

#include <utility>

#include "shape.hpp"
#include "vectors.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Vec3 a, Vec3 b) : a(std::move(a)), b(std::move(b)) { }

    Rectangle& setNormal(Vec3 value);

    void construct() override;
private:
    Vec3 a, b;

    std::optional<Vec3> normal;
};

#endif
