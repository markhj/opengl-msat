#ifndef OPENGL_MSAT_SHADER_HPP
#define OPENGL_MSAT_SHADER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/bindable/bindable.hpp"
#include "opengl_msat/shared/shader_types.hpp"
#include "vertex_sbldr.hpp"
#include "fragment_sbldr.hpp"
#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/camera/camera.hpp"
#include "opengl_msat/shared/lights.hpp"
#include <iostream>
#include <map>

class ShaderProgram : public Bindable {
public:
    void compile();

    void setSource(ShaderStage stage, std::string source);

    void fromBuilder(VertexShaderBuilder builder);

    void fromBuilder(FragmentShaderBuilder builder);

    [[nodiscard]] unsigned int getProgramId() const;

    void doBind() override;

    void doUnbind() override;

    GLint getLocation(std::string of);

    void uniform(std::string name, int value);

    void uniform(std::string name, unsigned int value);

    void uniform(std::string name, float value);

    void uniform(std::string name, Vec3 value);

    void uniform(std::string name, Mat4 value);

    void uniform(std::string name, DirectionalLight value);

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
