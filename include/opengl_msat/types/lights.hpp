#ifndef OPENGL_MSAT_LIGHTS_HPP
#define OPENGL_MSAT_LIGHTS_HPP

#include <cmath>
#include "opengl_msat/types/color.hpp"

/**
 * Directional light
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lights/directional/
 */
struct DirectionalLight {
    Vec3 direction;
    Color ambientColor, diffuseColor, specularColor;
};

/**
 * Point light
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lights/point-light/
 */
struct PointLight {
    Vec3 position;
    Color ambientColor, diffuseColor, specularColor;
    float constant = 1.0, linear = 0.01, quadratic = 0.032;
};

/**
 * Spot light
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lights/spot-light/
 */
struct SpotLight {
    Vec3 position, direction;
    Color ambientColor, diffuseColor, specularColor;
    float cutOff = 12.0;
    float constant = 1.0, linear = 0.01, quadratic = 0.032;
};

#endif
