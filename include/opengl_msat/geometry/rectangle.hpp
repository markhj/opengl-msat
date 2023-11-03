#ifndef OPENGL_MSAT_RECTANGLE_HPP
#define OPENGL_MSAT_RECTANGLE_HPP

#include <utility>

#include "shape.hpp"
#include "vectors.hpp"

class Rectangle3D : public Shape3D {
public:
    Rectangle3D(Vec3 a, Vec3 b) : a(std::move(a)), b(std::move(b)) { }

    Rectangle3D& setNormal(Vec3 value);

    void construct() override;
private:
    Vec3 a, b;

    std::optional<Vec3> normal;
};

class Rectangle2D : public Shape2D {
public:
    Rectangle2D(Vec2 a, Vec2 b) : a(std::move(a)), b(std::move(b)) { }

    Rectangle2D& setNormal(Vec3 value);

    void construct() override;

private:
    Vec2 a, b;

    std::optional<Vec2> normal;

};

#endif
