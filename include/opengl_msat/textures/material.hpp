#ifndef OPENGL_MSAT_MATERIAL_HPP
#define OPENGL_MSAT_MATERIAL_HPP

#include <optional>
#include "opengl_msat/types/color.hpp"
#include "texture.hpp"

/**
 * Material
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/textures/materials/
 */
class Material {
public:
    Color diffuseColor;
    std::optional<Texture*> albedoTexture;
    float shininess = 32.0;
};

#endif
