#include "opengl_msat/shader/shader_builder.hpp"

std::string ShaderBuilder::build()
{
    buildSource();

    return lines;
}

void ShaderBuilder::addLine(const std::string &line)
{
    lines += "\n" + line;
}

void ShaderBuilder::in(VertexAttribute attribute)
{
    std::string prefix = getVertexAttributeShaderPrefix(attribute);
    if (!prefix.empty()) {
        prefix += " ";
    }
    addLine(prefix
            + "in "
            + getVertexAttributeShaderType(attribute)
            + " "
            + getVertexAttributeVarName(attribute)
            + ";");
}

void ShaderBuilder::out(VertexAttribute attribute)
{
    std::string prefix = getVertexAttributeShaderPrefix(attribute);
    if (!prefix.empty()) {
        prefix += " ";
    }
    addLine(prefix
            + "out "
            + getVertexAttributeShaderType(attribute)
            + " "
            + getVertexAttributeVarName(attribute)
            + ";");
}

void ShaderBuilder::print()
{
    std::cout << "===\n" << lines << "===\n" << std::endl;
}
