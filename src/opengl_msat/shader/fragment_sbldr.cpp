#include "opengl_msat/shader/fragment_sbldr.hpp"

void FragmentShaderBuilder::buildSource()
{
    addLine("out vec4 result;");

    bool hasColor = false;

    for (VertexAttribute attr : attributes) {
        in(attr);

        std::string varName = getVertexAttributeVarName(attr);
        if (varName == "color") {
            hasColor = true;
        }
    }

    addLine("void main() {");

    // When no other instructions are provided
    if (hasColor) {
        addLine("result = vec4(color, 1.0);");
    } else {
        addLine("result = vec4(1.0, 1.0, 1.0, 1.0);");
    }

    addLine("}");
}
