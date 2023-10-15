#ifndef OPENGL_MSAT_COLOR_HPP
#define OPENGL_MSAT_COLOR_HPP

#include "opengl_msat/geometry/vectors.hpp"

class Color : public Vec3 {
public:
    explicit Color(float scalar);

    Color(float r, float g, float b);

};

class ColorRGBA : public Vec4 {
public:
    explicit ColorRGBA(float scalar);

    ColorRGBA(float r, float g, float b);

    ColorRGBA(float r, float g, float b, float a);
};

#endif
