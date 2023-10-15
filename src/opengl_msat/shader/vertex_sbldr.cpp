#include <iostream>
#include "opengl_msat/shader/vertex_sbldr.hpp"

void VertexShaderBuilder::buildSource()
{
    int loc = 0;
    int posSize = 0;
    for (VertexAttribute attr : attributes) {
        std::string varName = getVertexAttributeVarName(attr);
        unsigned int size = getVertexAttributeSize(attr);
        lines += "\nlayout (location = "
                + std::to_string(loc)
                + ") in "
                + getVertexAttributeShaderType(attr)
                + " vbo_"
                + varName
                + ";";
        loc++;

        if (varName == "pos") {
            posSize = size;
        }
    }

    for (VertexAttribute attr : attributes) {
        out(attr);
    }

    addLine("uniform mat4 projection;");

    addLine("void main() {");

    if (projection.has_value()) {
        addLine("gl_Position = projection * vec4(vbo_pos, 1.0);");
    } else {
        addLine("gl_Position = vec4(vbo_pos, 1.0);");
    }

    for (VertexAttribute attr : attributes) {
        std::string varName = getVertexAttributeVarName(attr);
        addLine(varName + " = vbo_" + varName + ";");
    }

    addLine("}");
}
