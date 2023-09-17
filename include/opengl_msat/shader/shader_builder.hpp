#ifndef OPENGL_MSAT_SHADER_BUILDER_HPP
#define OPENGL_MSAT_SHADER_BUILDER_HPP

#include <iostream>
#include "opengl_msat/shared/vertex_types.hpp"

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
        addLine("in vec"
                 + std::to_string(getVertexAttributeSize(attribute))
                 + " "
                 + getVertexAttributeVarName(attribute)
                 + ";");
    }

    void out(VertexAttribute attribute)
    {
        addLine("out vec"
                 + std::to_string(getVertexAttributeSize(attribute))
                 + " "
                 + getVertexAttributeVarName(attribute)
                 + ";");
    }
protected:
    std::string lines = "#version 330 core\n";
};

#endif
