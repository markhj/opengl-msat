#include "opengl_msat/shader/fragment_sbldr.hpp"
#include "opengl_msat/shader/glsl.hpp"

void FragmentShaderBuilder::buildSource()
{
    addLine("out vec4 result;");

    bool hasColor = false;
    int colorSize = 3;

    for (VertexAttribute attr : attributes) {
        in(attr);

        std::string varName = getVertexAttributeVarName(attr);
        if (varName == "color") {
            hasColor = true;
            colorSize = getVertexAttributeSize(attr);
        }
    }

    // Camera
    addLine("struct Camera { vec3 position; vec3 target; };");
    addLine("uniform Camera camera;");

    addLine("const float M_PI = 3.141592;");

    // Materials
    if (enableMaterials) {
        addLine("struct Material { vec3 diffuseColor; int albedoTextureUnit; float shininess; };");
        addLine("uniform Material[" + std::to_string(materialSlots) + "] materials;");

        addLine("uniform sampler2D[" + std::to_string(textureSlots) + "] textures;");
    }

    if (enableLighting) {
        addLine(lightStructs);
        addLine(lightFunctions);

        addLine("uniform DirectionalLight[" + std::to_string(lightSlots) + "] directionalLights;\n"
                "uniform PointLight[" + std::to_string(lightSlots) + "] pointLights;\n"
                "uniform SpotLight[" + std::to_string(lightSlots) + "] spotLights;\n"
                "uniform int numDirectionalLights = 0;\n"
                "uniform int numPointLights = 0;\n"
                "uniform int numSpotLights = 0;\n");
    }

    if (enableMaterials) {
        addLine("vec3 getTextureRGB(int unit) {\n");
        for (unsigned int i = 0; i < textureSlots; i++) {
            addLine("if (unit == " + std::to_string(i) + ") { return texture(textures[" + std::to_string(i) + "], texCoords).rgb; }");
        }
        addLine("return vec3(0.0);\n}\n");
    }

    addLine("void main() {\n");

    if (enableLighting) {
        std::string shininess = enableMaterials
                ? "materials[int(materialId)].shininess"
                : "32.0";
        addLine("vec3 clr = vec3(0.0, 0.0, 0.0);\n"
                "for (int i = 0; i < numDirectionalLights; i++) {\n"
                "clr += calcDirectionalLight(directionalLights[i], " + shininess + ");\n"
                "}\n"
                "for (int i = 0; i < numPointLights; i++) {\n"
                "clr += calcPointLight(pointLights[i], " + shininess + ");\n"
                "}\n"
                "for (int i = 0; i < numSpotLights; i++) {\n"
                "clr += calcSpotLight(spotLights[i], " + shininess + ");\n"
                "}\n"
        );
    }

    if (enableLighting && enableMaterials) {
        addLine(
                "if (materials[int(materialId)].albedoTextureUnit >= 0) {\n"
                "vec3 tx = getTextureRGB(materials[int(materialId)].albedoTextureUnit);\n"
                "result = vec4(clr * tx, 1.0);\n"
                "} else {\n"
                "result = vec4(clr * materials[int(materialId)].diffuseColor, 1.0);\n"
                "}\n"
                );
    } else if (enableLighting && colorSize == 3) {
        addLine("result = vec4(clr * color, 1.0);\n");
    } else if (enableLighting && colorSize == 4) {
        addLine("result = vec4(clr, 1.0) * color;\n");
    } else if (hasColor && colorSize == 3) {
        addLine("result = vec4(color, 1.0);\n");
    } else if (hasColor && colorSize == 4) {
        addLine("result = color;\n");
    } else {
        addLine("result = vec4(1.0, 1.0, 1.0, 1.0);\n");
    }

    addLine("}");
}

FragmentShaderBuilder& FragmentShaderBuilder::lighting()
{
    enableLighting = true;
    return *this;
}

FragmentShaderBuilder &FragmentShaderBuilder::materials()
{
    enableMaterials = true;
    return *this;
}
