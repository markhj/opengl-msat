#ifndef OPENGL_MSAT_LIGHTS_HPP
#define OPENGL_MSAT_LIGHTS_HPP

#include <cmath>
#include "opengl_msat/types/color.hpp"

struct DirectionalLight {
    Vec3 direction;
    Color ambientColor, diffuseColor, specularColor;
};

struct PointLight {
    Vec3 position;
    Color ambientColor, diffuseColor, specularColor;
};

struct SpotLight {
    Vec3 position, direction;
    Color ambientColor, diffuseColor, specularColor;
};

#endif
