#include <iostream>
#include "opengl_msat/shader/vertex_sbldr.hpp"

const char* VertexShaderBuilder::build()
{
    std::string lines = "#version 330";

    int loc = 0;
    for (VertexAttribute attr : attributes) {
        std::string varName = getVertexAttributeVarName(attr);
        lines += "\nlayout (location = "
                + std::to_string(loc)
                + ") in vec"
                + std::to_string(getVertexAttributeSize(attr))
                + " vbo_"
                + varName
                + ";";
        loc++;
    }

    lines += "\n";

    for (VertexAttribute attr : attributes) {
        std::string varName = getVertexAttributeVarName(attr);
        lines += "\nout vec"
                + std::to_string(getVertexAttributeSize(attr))
                + " "
                + getVertexAttributeVarName(attr)
                + ";";
    }

    lines += "\n\nvoid main() {";
    lines += "\n\tgl_Position = vec4(vbo_pos, 1.0);";
    for (VertexAttribute attr : attributes) {
        std::string varName = getVertexAttributeVarName(attr);
        lines += "\n\t"
                + varName
                + " = vbo_"
                + varName
                + ";";
    }
    lines += "\n}";

    return lines.c_str();
}