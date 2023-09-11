#include <vector>
#include "opengl_msat/shader/shader.hpp"

void ShaderProgram::compileShaderStage(ShaderStage stage)
{
    auto source = sources.find(stage);
    if (source == sources.end()) {
        return;
    }

    std::string sourceCode = source->second;
    const char* cstr = sourceCode.c_str();

    GLuint shader = glCreateShader(getShaderStage(stage));
    glShaderSource(shader, 1, &cstr, nullptr);
    glCompileShader(shader);

    GLint compileStatus;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != GL_TRUE) {
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> log(logLength);
        glGetShaderInfoLog(shader, logLength, nullptr, log.data());

        std::cerr << "\n" << getShaderTypeName(stage) << " shader:\n" << log.data() << "\n"
            << sourceCode << "\n===================\n" << std::endl;
        compileErrors = true;
    }

    glAttachShader(programId, shader);
}

void ShaderProgram::compile()
{
    compileErrors = false;
    programId = glCreateProgram();

    compileShaderStage(ShaderStage::Vertex);
    compileShaderStage(ShaderStage::TessControl);
    compileShaderStage(ShaderStage::TessEval);
    compileShaderStage(ShaderStage::Geometry);
    compileShaderStage(ShaderStage::Fragment);
    compileShaderStage(ShaderStage::Compute);

    if (compileErrors) {
        return;
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

void ShaderProgram::setSource(ShaderStage stage, std::string source)
{
    sources.insert(std::make_pair(stage, source));
}

const char *ShaderProgram::getShaderTypeName(ShaderStage stage)
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

GLenum ShaderProgram::getShaderStage(ShaderStage stage)
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
