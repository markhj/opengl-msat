#ifndef OPENGL_MSAT_SHADER_HPP
#define OPENGL_MSAT_SHADER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/contracts/bindable.hpp"
#include "opengl_msat/shared/shader_types.hpp"
#include "vertex_sbldr.hpp"
#include "fragment_sbldr.hpp"
#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/camera/camera.hpp"
#include <iostream>
#include <map>

class ShaderProgram : public Bindable {
public:
    void compile();

    void setSource(ShaderStage stage, std::string source);

    void fromBuilder(VertexShaderBuilder builder)
    {
        setSource(ShaderStage::Vertex, builder.build());
    }

    void fromBuilder(FragmentShaderBuilder builder)
    {
        setSource(ShaderStage::Fragment, builder.build());
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

    GLint getLocation(const char* of)
    {
        return glGetUniformLocation(getProgramId(), of);
    }

    void uniform(const char* name, Mat4 value);

    void uniform(Camera& camera);
private:
    GLuint programId;

    bool compileErrors = false;

    std::map<ShaderStage, std::string> sources = {};

    const char* getShaderTypeName(ShaderStage stage);

    GLenum getShaderStage(ShaderStage stage);

    void compileShaderStage(ShaderStage stage);
};

#endif
