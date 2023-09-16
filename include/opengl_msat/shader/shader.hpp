#ifndef OPENGL_MSAT_SHADER_HPP
#define OPENGL_MSAT_SHADER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/bindable/bindable.hpp"
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

    void fromBuilder(VertexShaderBuilder builder);

    void fromBuilder(FragmentShaderBuilder builder);

    unsigned int getProgramId() const;

    void doBind();

    void doUnbind();

    GLint getLocation(const char* of);

    void uniform(const char* name, int value);

    void uniform(const char* name, unsigned int value);

    void uniform(const char* name, float value);

    void uniform(const char* name, Vec3 value);

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
