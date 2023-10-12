#ifndef OPENGL_MSAT_FRAGMENT_SBLDR_HPP
#define OPENGL_MSAT_FRAGMENT_SBLDR_HPP

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "shader_builder.hpp"
#include "opengl_msat/types/vertex_types.hpp"

class FragmentShaderBuilder : public ShaderBuilder {
public:
    explicit FragmentShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
    {}

    void buildSource() override;

    FragmentShaderBuilder& lighting();

    FragmentShaderBuilder& materials();

    unsigned int lightSlots = 20;

    unsigned int materialSlots = 20;

private:
    std::vector<VertexAttribute> attributes;

    bool enableLighting = false,
        enableMaterials = false;

};

#endif
