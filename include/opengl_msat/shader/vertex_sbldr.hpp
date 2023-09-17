#ifndef OPENGL_MSAT_VERTEX_SBLDR_HPP
#define OPENGL_MSAT_VERTEX_SBLDR_HPP

#include "shader_builder.hpp"
#include "opengl_msat/shared/vertex_types.hpp"
#include "opengl_msat/shared/projections.hpp"
#include <utility>
#include <vector>

class VertexShaderBuilder : public ShaderBuilder {
public:
    explicit VertexShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
        { }

    void buildSource() override;

    VertexShaderBuilder& setProjection(Projection value);
private:
    std::vector<VertexAttribute> attributes;

    Projection projection = Projection::None;
};

#endif
