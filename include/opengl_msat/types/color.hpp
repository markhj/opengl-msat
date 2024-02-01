#ifndef OPENGL_MSAT_COLOR_HPP
#define OPENGL_MSAT_COLOR_HPP

#include <vector>
#include "opengl_msat/geometry/vectors.hpp"

/**
 * Color (RGB)
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/misc/color/
 */
class Color : public Vec3 {
public:
    explicit Color(float scalar);

    Color(float r, float g, float b);

};

/**
 * Color (RGB + alpha)
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/misc/color/
 */
class ColorRGBA : public Vec4 {
public:
    explicit ColorRGBA(float scalar);

    ColorRGBA(float r, float g, float b);

    ColorRGBA(float r, float g, float b, float a);
};

/**
 * Coloring
 *
 * Object which can describe multiple colors
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/misc/coloring/
 */
class Coloring {
public:
    explicit Coloring(const std::vector<Color>& colors) : colors(colors) { }

    Color get(int index);

    /**
     * When true: When get is called, and the index is out of bounds, the cursor of
     * the vector will return to 0
     *
     * When false: When get is called with an index which is out of bounds, the last color
     * of the vector will be returned
     */
    bool repeat = true;

private:
    std::vector<Color> colors;

};

#endif
