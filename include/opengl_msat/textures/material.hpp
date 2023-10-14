#ifndef OPENGL_MSAT_MATERIAL_HPP
#define OPENGL_MSAT_MATERIAL_HPP

#include <optional>
#include "opengl_msat/types/color.hpp"

class Material {
public:
    Color diffuseColor;
    std::optional<int> albedoTextureUnit;
};

#endif
