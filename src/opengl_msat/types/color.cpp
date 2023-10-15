#include "opengl_msat/types/color.hpp"

Color::Color(float scalar) : Vec3(scalar) {

}

Color::Color(float r, float g, float b) : Vec3(r, g, b)
{

}

ColorRGBA::ColorRGBA(float scalar) : Vec4(scalar, scalar, scalar, 1.0)
{

}

ColorRGBA::ColorRGBA(float r, float g, float b) : Vec4(r, g, b, 1.0)
{

}

ColorRGBA::ColorRGBA(float r, float g, float b, float a) : Vec4(r, g, b, a)
{

}
