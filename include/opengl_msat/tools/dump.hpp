#ifndef OPENGL_MSAT_DUMP_HPP
#define OPENGL_MSAT_DUMP_HPP

#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/geometry/vectors.hpp"

class Dump {
public:
    static void dump(Mat4 value);

    static void dump(Vec3 value);

    static void dump(Vec2 value);
};

#endif
