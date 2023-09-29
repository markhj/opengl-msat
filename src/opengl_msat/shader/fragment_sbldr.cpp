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

    // Camera
    addLine("struct Camera { vec3 position; vec3 target; };");
    addLine("uniform Camera camera;");

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

        addLine("vec3 calcDirectionalLight(DirectionalLight light) {"
                "float shininess = 32.0;"
                "vec3 viewDir = normalize(camera.position - pos);"
                "vec3 lightDir = normalize(-light.direction);"
                "vec3 diffuse = light.diffuseColor * max(dot(normal, lightDir), 0.0);"
                "vec3 reflectDir = reflect(-lightDir, normal);"
                "vec3 specular = light.specularColor * pow(max(dot(viewDir, reflectDir), 0.0), shininess);"
                "return light.ambientColor + light.diffuseColor + diffuse + specular;"
                "}");
    }

    addLine("void main() {");

    // When no other instructions are provided
    if (enableLighting) {
        addLine("vec3 clr = vec3(0.0, 0.0, 0.0);"
                "for (int i = 0; i <= numDirectionalLights; i++) {"
                    "clr += calcDirectionalLight(directionalLights[i]);"
                "}"
                "for (int i = 0; i <= numPointLights; i++) {"
                "}"
                "for (int i = 0; i <= numSpotLights; i++) {"
                "}"
                "result = vec4(clr * color, 1.0);");
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
