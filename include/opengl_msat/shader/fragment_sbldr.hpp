#ifndef OPENGL_MSAT_FRAGMENT_SBLDR_HPP
#define OPENGL_MSAT_FRAGMENT_SBLDR_HPP

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "shader_builder.hpp"
#include "opengl_msat/types/vertex_types.hpp"

/**
 * Fragment shader builder
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/getting-started/shader-builders/
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/shader/fragment-shader-builder/
 */
class FragmentShaderBuilder : public ShaderBuilder {
public:
    explicit FragmentShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
    {}

    void buildSource() override;

    FragmentShaderBuilder& lighting();

    FragmentShaderBuilder& materials();

    unsigned int lightSlots = 32;

    unsigned int materialSlots = 32;

    /**
     * If you bind to a texture unit above this value - 1, the texture will most likely
     * not be rendered.
     */
    unsigned int textureSlots = 32;

private:
    std::vector<VertexAttribute> attributes;

    bool enableLighting = false,
        enableMaterials = false;

};

#endif
