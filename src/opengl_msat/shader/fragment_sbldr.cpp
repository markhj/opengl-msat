#include "opengl_msat/shader/fragment_sbldr.hpp"

std::string FragmentShaderBuilder::build()
{
    std::string lines = "#version 330 core\n";
    lines += "out vec4 result;\n";

    bool hasColor = false;

    for (VertexAttribute attr : attributes) {
        std::string varName = getVertexAttributeVarName(attr);
        lines += "\nin vec"
                 + std::to_string(getVertexAttributeSize(attr))
                 + " "
                 + varName
                 + ";";

        if (varName == "color") {
            hasColor = true;
        }
    }

    lines += "\n\nvoid main() {";

    // When no other instructions are provided
    if (hasColor) {
        lines += "\n\tresult = vec4(color, 1.0);";
    } else {
        lines += "\n\tresult = vec4(1.0, 1.0, 1.0, 1.0);";
    }

    lines += "\n}";

    return lines;
}
