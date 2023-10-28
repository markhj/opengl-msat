#ifndef OPENGL_MSAT_SHADER_TYPES_HPP
#define OPENGL_MSAT_SHADER_TYPES_HPP

#include "opengl_msat/common.h"

/**
 * Shader stage
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/shader-stage/
 */
enum ShaderStage {
    Vertex = GL_VERTEX_SHADER,
    Fragment = GL_FRAGMENT_SHADER,
    Geometry = GL_GEOMETRY_SHADER,
    Compute = GL_COMPUTE_SHADER,
    TessControl = GL_TESS_CONTROL_SHADER,
    TessEval = GL_TESS_EVALUATION_SHADER
};

#endif
