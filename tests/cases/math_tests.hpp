#ifndef OPENGL_MSAT_MATH_TESTS_HPP
#define OPENGL_MSAT_MATH_TESTS_HPP

#include "bbunit.hpp"
#include "opengl_msat/public.hpp"

class MathTest : public BBUnit::TestCase {
public:
    void tangent();

    void bitangent();

private:
    VertexElement3D a {
        .position = Vec3(0.0),
        .textureCoords = Vec2(0.0),
    },
    b {
        .position = Vec3(1.0),
        .textureCoords = Vec2(1.0),
    },
    c {
        .position = Vec3(1.0, 0.0, 0.0),
        .textureCoords = Vec2(1.0, 0.0),
    };

};

#endif
