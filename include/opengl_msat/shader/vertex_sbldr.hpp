#ifndef OPENGL_MSAT_VERTEX_SBLDR_HPP
#define OPENGL_MSAT_VERTEX_SBLDR_HPP

#include "shader_builder.hpp"
#include "opengl_msat/types/vertex_types.hpp"
#include "opengl_msat/types/projections.hpp"
#include <utility>
#include <vector>

/**
 * Shader builder
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/getting-started/shader-builders/
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/shader/vertex-shader-builder/
 */
class VertexShaderBuilder : public ShaderBuilder {
public:
    explicit VertexShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
        { }

    void buildSource() override;

    std::optional<Projection*> projection;

private:
    std::vector<VertexAttribute> attributes;

};

#endif
