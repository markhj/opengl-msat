#include <iostream>
#include "opengl_msat/shader/vertex_sbldr.hpp"

std::string VertexShaderBuilder::build()
{
    std::string lines = "#version 330 core";

    int loc = 0;
    int posSize = 0;
    for (VertexAttribute attr : attributes) {
        std::string varName = getVertexAttributeVarName(attr);
        unsigned int size = getVertexAttributeSize(attr);
        lines += "\nlayout (location = "
                + std::to_string(loc)
                + ") in vec"
                + std::to_string(size)
                + " vbo_"
                + varName
                + ";";
        loc++;

        if (varName == "pos") {
            posSize = size;
        }
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

    if (projection != Projection::None) {
        lines += "\nuniform mat4 model;";
        lines += "\nuniform mat4 view;";
        lines += "\nuniform mat4 projection;";
    }

    lines += "\n\nvoid main() {";

    if (posSize == 2) {
        lines += "\n\tgl_Position = vec4(vbo_pos, 0.0, 1.0);";
    } else if (projection != Projection::None) {
        lines += "\n\tgl_Position = projection * model * view * vec4(vbo_pos, 1.0);";
    } else {
        lines += "\n\tgl_Position = vec4(vbo_pos, 1.0);";
    }

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

VertexShaderBuilder &VertexShaderBuilder::setProjection(Projection value)
{
    projection = value;

    return *this;
}
