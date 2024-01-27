#ifndef OPENGL_MSAT_REGULAR_POLYGON_HPP
#define OPENGL_MSAT_REGULAR_POLYGON_HPP

#include "shape2d.hpp"

class RegularPolygon2D : public Shape2D {
public:
    RegularPolygon2D(unsigned int sides, double radius) : sides(sides), radius(radius) { }

    void construct() override;

private:
    unsigned int sides;

    double radius;

};

#endif
