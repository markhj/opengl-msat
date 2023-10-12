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
        unsigned int size = getVertexAttributeSize(attribute);
        addLine((size == 1 ? "in " : "in ")
                 + (size == 1 ? "float" : "vec" + std::to_string(size))
                 + " "
                 + getVertexAttributeVarName(attribute)
                 + ";");
    }

    void out(VertexAttribute attribute)
    {
        unsigned int size = getVertexAttributeSize(attribute);
        addLine((size == 1 ? "out " : "out ")
                 + (size == 1 ? "float" : "vec" + std::to_string(size))
                 + " "
                 + getVertexAttributeVarName(attribute)
                 + ";");
    }
protected:
    std::string lines = "#version 330 core\n";
};

#endif
