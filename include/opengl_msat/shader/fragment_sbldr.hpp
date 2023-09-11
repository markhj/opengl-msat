#ifndef OPENGL_MSAT_FRAGMENT_SBLDR_HPP
#define OPENGL_MSAT_FRAGMENT_SBLDR_HPP

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "opengl_msat/contracts/shader_builder.hpp"
#include "opengl_msat/shared/vertex_types.hpp"

class FragmentShaderBuilder : public ShaderBuilder {
public:
    explicit FragmentShaderBuilder(std::vector<VertexAttribute> attributes)
        : attributes(std::move(attributes))
    {}

    std::string build()
    {
        std::string lines = "#version 330 core\n";
        lines += "out vec4 result;\n";

        for (VertexAttribute attr : attributes) {
            std::string varName = getVertexAttributeVarName(attr);
            lines += "\nin vec"
                     + std::to_string(getVertexAttributeSize(attr))
                     + " "
                     + varName
                     + ";";
        }

        lines += "\n\nvoid main() {";

        // When no other instructions are provided
        lines += "\n\tresult = vec4(color, 1.0);";

        lines += "\n}";

        return lines;
    }
private:
    std::vector<VertexAttribute> attributes;
};

#endif
