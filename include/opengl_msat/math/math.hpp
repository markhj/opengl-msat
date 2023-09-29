#ifndef OPENGL_MSAT_MATH_HPP
#define OPENGL_MSAT_MATH_HPP


#include "opengl_msat/geometry/vectors.hpp"

class Math {
public:
    [[nodiscard]] static Vec3 calculateNormal(Vec3 a, Vec3 b, Vec3 c);
};

#endif
