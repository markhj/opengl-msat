#include <vector>
#include "opengl_msat/shader/shader.hpp"

void ShaderProgram::compile()
{
    programId = glCreateProgram();

    for (auto source : sources) {
        GLuint shader = glCreateShader(getShaderStage(source.first));
        glShaderSource(shader, 1, &source.second, nullptr);
        glCompileShader(shader);

        GLint compileStatus;

        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
        if (compileStatus != GL_TRUE) {
            GLint logLength;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
            std::vector<GLchar> log(logLength);
            glGetShaderInfoLog(shader, logLength, nullptr, log.data());

            std::cerr << getShaderTypeName(source.first) << " shader: " << log.data() << std::endl;
        }

        glAttachShader(programId, shader);
    }

    glLinkProgram(programId);

    GLint linkStatus;
    glGetProgramiv(programId, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
        GLint logLength;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> log(logLength);
        glGetProgramInfoLog(programId, logLength, nullptr, log.data());

        std::cerr << "Shader program linking failed: " << log.data() << std::endl;
    }
}

void ShaderProgram::setSource(ShaderStage stage, const char *source)
{
    sources.insert(std::make_pair(stage, source));
}
