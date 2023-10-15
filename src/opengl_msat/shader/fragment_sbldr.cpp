#include "opengl_msat/shader/fragment_sbldr.hpp"

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
        addLine("struct Material { vec3 diffuseColor; int albedoTextureUnit; };");
        addLine("uniform Material[" + std::to_string(materialSlots) + "] materials;");

        addLine("uniform sampler2D[" + std::to_string(textureSlots) + "] textures;");
    }

    if (enableLighting) {
        addLine("struct DirectionalLight {\n"
                "vec3 direction, ambientColor, diffuseColor, specularColor;\n"
                "};\n");

        addLine("struct PointLight {\n"
                "vec3 position, ambientColor, diffuseColor, specularColor;\n"
                "float constant, linear, quadratic;\n"
                "};");

        addLine("struct SpotLight {\n"
                "vec3 position, direction, ambientColor, diffuseColor, specularColor;\n"
                "float cutOff;\n"
                "float constant, linear, quadratic;\n"
                "};");

        addLine("uniform DirectionalLight[" + std::to_string(lightSlots) + "] directionalLights;\n"
                "uniform PointLight[" + std::to_string(lightSlots) + "] pointLights;\n"
                "uniform SpotLight[" + std::to_string(lightSlots) + "] spotLights;\n"
                "uniform int numDirectionalLights = 0;\n"
                "uniform int numPointLights = 0;\n"
                "uniform int numSpotLights = 0;\n");

        addLine("vec3 calcDirectionalLight(DirectionalLight light) {\n"
                "float shininess = 32.0;\n"
                "vec3 viewDir = normalize(camera.position - pos);\n"
                "vec3 lightDir = normalize(-light.direction);\n"
                "vec3 diffuse = light.diffuseColor * max(dot(normal, lightDir), 0.0);\n"
                "vec3 reflectDir = reflect(-lightDir, normal);\n"
                "vec3 specular = light.specularColor * pow(max(dot(viewDir, reflectDir), 0.0), shininess);\n"
                "return light.ambientColor + diffuse + specular;\n"
                "}");

        addLine("vec3 calcPointLight(PointLight light) {\n"
                "float shininess = 32.0;\n"
                "vec3 viewDir = normalize(camera.position - pos);\n"
                "vec3 lightDir = normalize(light.position - pos);\n"
                "float diff = max(dot(normal, lightDir), 0.0);\n"
                "vec3 reflectDir = reflect(-lightDir, normal);\n"
                "float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);\n"
                "float distance = length(light.position - pos);\n"
                "float attenuation = 1.0 / (light.constant + light.linear * distance +\n"
                "light.quadratic * (distance * distance));\n"
                "vec3 ambient  = attenuation * light.ambientColor;\n"
                "vec3 diffuse  = attenuation * light.diffuseColor * diff;\n"
                "vec3 specular = attenuation * light.specularColor * spec;\n"
                "return (ambient + diffuse + specular);\n"
                "}\n");

        addLine("vec3 calcSpotLight(SpotLight light) {\n"
                "float shininess = 32.0;\n"
                "vec3 viewDir = normalize(camera.position - pos);\n"
                "vec3 result = vec3(0.0, 0.0, 0.0);\n"
                "vec3 lightDir = normalize(light.position - pos);\n"
                "float theta = dot(lightDir, normalize(-light.direction));\n"
                "float cutOff = cos(light.cutOff * M_PI / 180);\n"
                "if (theta > cutOff) {\n"
                    "vec3 ambient = light.ambientColor;\n"
                    "vec3 norm = normalize(normal);\n"
                    "float diff = max(dot(norm, lightDir), 0.0);\n"
                    "vec3 diffuse = light.diffuseColor * diff;\n"
                    "vec3 reflectDir = reflect(-lightDir, norm);\n"
                    "float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);\n"
                    "vec3 specular = light.specularColor * spec;\n"
                    "float distance = length(light.position - pos);\n"
                    "float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));\n"
                    "diffuse   *= attenuation;\n"
                    "specular *= attenuation;\n"
                    "return ambient + diffuse + specular;\n"
                "}\n"
                "return vec3(0.0, 0.0, 0.0);\n"
            "}");
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
        addLine("vec3 clr = vec3(0.0, 0.0, 0.0);\n"
                "for (int i = 0; i < numDirectionalLights; i++) {\n"
                "clr += calcDirectionalLight(directionalLights[i]);\n"
                "}\n"
                "for (int i = 0; i < numPointLights; i++) {\n"
                "clr += calcPointLight(pointLights[i]);\n"
                "}\n"
                "for (int i = 0; i < numSpotLights; i++) {\n"
                "clr += calcSpotLight(spotLights[i]);\n"
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
