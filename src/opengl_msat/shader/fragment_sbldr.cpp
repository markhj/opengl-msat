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

    if (enableLighting) {
        addLine("struct DirectionalLight {"
                "vec3 direction, ambientColor, diffuseColor, specularColor;"
                "};");

        addLine("struct PointLight {"
                "vec3 position, ambientColor, diffuseColor, specularColor;"
                "};");

        addLine("struct SpotLight {"
                "vec3 position, direction, ambientColor, diffuseColor, specularColor;"
                "};");

        addLine("uniform DirectionalLight[" + std::to_string(lightSlots) + "] directionalLights;"
                "uniform PointLight[" + std::to_string(lightSlots) + "] pointLights;"
                "uniform SpotLight[" + std::to_string(lightSlots) + "] spotLights;"
                "uniform int numDirectionalLights = 0;"
                "uniform int numPointLights = 0;"
                "uniform int numSpotLights = 0;");
    }

    addLine("void main() {");

    // When no other instructions are provided
    if (enableLighting) {
        addLine("vec4 clr = vec4(color, 1.0);"
                "for (int i = 0; i <= numDirectionalLights; i++) {"
                "clr *= vec4(directionalLights[i].ambientColor, 1.0);"
                "}"
                "for (int i = 0; i <= numPointLights; i++) {"
                "}"
                "for (int i = 0; i <= numSpotLights; i++) {"
                "}"
                "result = clr;");
    } else if (hasColor) {
        addLine("result = vec4(color, 1.0);");
    } else {
        addLine("result = vec4(1.0, 1.0, 1.0, 1.0);");
    }

    addLine("}");
}

FragmentShaderBuilder& FragmentShaderBuilder::lighting()
{
    enableLighting = true;
    return *this;
}

FragmentShaderBuilder& FragmentShaderBuilder::setLightSlots(int slots)
{
    lightSlots = slots;
    return *this;
}
