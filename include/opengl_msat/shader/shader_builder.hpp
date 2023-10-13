#ifndef OPENGL_MSAT_SHADER_BUILDER_HPP
#define OPENGL_MSAT_SHADER_BUILDER_HPP

#include <iostream>
#include "opengl_msat/types/vertex_types.hpp"

class ShaderBuilder {
public:
    virtual void buildSource() = 0;

    std::string build();

    void addLine(const std::string& line)
    {
        lines += "\n" + line;
    }

    void in(VertexAttribute attribute)
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

    void out(VertexAttribute attribute)
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

    void print()
    {
        std::cout << "===\n" << lines << "===\n" << std::endl;
    }
protected:
    std::string lines = "#version 330 core\n";
};

#endif
