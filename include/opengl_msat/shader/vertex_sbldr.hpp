#ifndef OPENGL_MSAT_VERTEX_SBLDR_HPP
#define OPENGL_MSAT_VERTEX_SBLDR_HPP

#include "opengl_msat/contracts/shader_builder.hpp"
#include "opengl_msat/shared/vertex_types.hpp"
#include <utility>
#include <vector>

class VertexShaderBuilder : public ShaderBuilder {
public:
    explicit VertexShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
        { }

    std::string build() override;
private:
    std::vector<VertexAttribute> attributes;
};

#endif
