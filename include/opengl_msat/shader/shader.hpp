#ifndef OPENGL_MSAT_SHADER_HPP
#define OPENGL_MSAT_SHADER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/contracts/bindable.hpp"
#include "opengl_msat/shared/shader_types.hpp"
#include "vertex_sbldr.hpp"
#include <iostream>
#include <map>

class ShaderProgram : public Bindable {
public:
    void compile();

    void setSource(ShaderStage stage, const char* source);

    void fromBuilder(VertexShaderBuilder builder)
    {
        setSource(ShaderStage::Vertex, builder.build());
    }

    unsigned int getProgramId() const
    {
        return programId;
    }

    void bind()
    {
        glUseProgram(getProgramId());
    }

    void unbind()
    {
        glUseProgram(0);
    }
private:
    GLuint programId;

    std::map<ShaderStage, const char*> sources = {};

    const char* getShaderTypeName(ShaderStage stage)
    {
        switch (stage) {
            case ShaderStage::Vertex:
                return "Vertex";
            case ShaderStage::Fragment:
                return "Fragment";
            case ShaderStage::Compute:
                return "Compute";
            case ShaderStage::Geometry:
                return "Geometry";
            case ShaderStage::TessControl:
                return "Tessellation control";
            case ShaderStage::TessEval:
                return "Tessellation evaluation";
            default:
                throw std::runtime_error("OpenGL MSAT: Missing implementation in getShaderStage");
        }
    }

    GLenum getShaderStage(ShaderStage stage)
    {
        switch (stage) {
            case ShaderStage::Vertex:
                return GL_VERTEX_SHADER;
            case ShaderStage::Fragment:
                return GL_FRAGMENT_SHADER;
            case ShaderStage::Compute:
                return GL_COMPUTE_SHADER;
            case ShaderStage::Geometry:
                return GL_GEOMETRY_SHADER;
            case ShaderStage::TessEval:
                return GL_TESS_EVALUATION_SHADER;
            case ShaderStage::TessControl:
                return GL_TESS_CONTROL_SHADER;
            default:
                throw std::runtime_error("OpenGL MSAT: Missing implementation in getShaderStage");
        }
    }
};

#endif
