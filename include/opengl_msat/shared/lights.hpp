#ifndef OPENGL_MSAT_LIGHTS_HPP
#define OPENGL_MSAT_LIGHTS_HPP

#include <cmath>
#include "opengl_msat/types/color.hpp"

struct Light {

};

struct LightWithDirection {
    Vec3 direction;
};

struct LightWithPosition {
    Vec3 position;
};

struct AmbientLight : public Light {
    Color ambientColor;
};

struct DiffuseLight : public Light {
    Color diffuseColor;
};

struct SpecularLight : public Light {
    Color specularColor;
};

struct DirectionalLight :
        public LightWithDirection,
        public AmbientLight,
        public DiffuseLight,
        public SpecularLight { };

struct PointLight :
        public LightWithPosition,
        public AmbientLight,
        public DiffuseLight,
        public SpecularLight { };

struct SpotLight :
        public LightWithDirection,
        public LightWithPosition,
        public AmbientLight,
        public DiffuseLight,
        public SpecularLight {
    float cutOff = cos(12 * M_PI / 180);
};

#endif
