#ifndef OPENGL_MSAT_FRAGMENT_SBLDR_HPP
#define OPENGL_MSAT_FRAGMENT_SBLDR_HPP

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "shader_builder.hpp"
#include "opengl_msat/shared/vertex_types.hpp"

class FragmentShaderBuilder : public ShaderBuilder {
public:
    explicit FragmentShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
    {}

    void buildSource() override;

    FragmentShaderBuilder& setLightSlots(int slots);

    FragmentShaderBuilder& lighting();

private:
    std::vector<VertexAttribute> attributes;

    bool enableLighting = false;

    int lightSlots = 20;

};

#endif
