#ifndef OPENGL_MSAT_FRAGMENT_SBLDR_HPP
#define OPENGL_MSAT_FRAGMENT_SBLDR_HPP

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "opengl_msat/contracts/shader_builder.hpp"
#include "opengl_msat/shared/vertex_types.hpp"

class FragmentShaderBuilder : public ShaderBuilder {
public:
    explicit FragmentShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
    {}

    std::string build();
private:
    std::vector<VertexAttribute> attributes;
};

#endif
