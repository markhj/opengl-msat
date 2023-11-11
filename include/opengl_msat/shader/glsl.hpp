#ifndef OPENGL_MSAT_GLSL_HPP
#define OPENGL_MSAT_GLSL_HPP

const char* lightStructs = R"(
struct DirectionalLight {
    vec3 direction, ambientColor, diffuseColor, specularColor;
};

struct PointLight {
    vec3 position, ambientColor, diffuseColor, specularColor;
    float constant, linear, quadratic;
};

struct SpotLight {
    vec3 position, direction, ambientColor, diffuseColor, specularColor;
    float cutOff;
    float constant, linear, quadratic;
};
)";

const char* lightFunctions = R"(
vec3 calcDirectionalLight(DirectionalLight light, float shininess) {
    vec3 viewDir = normalize(camera.position - pos);
    vec3 lightDir = normalize(-light.direction);
    vec3 diffuse = light.diffuseColor * max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 specular = light.specularColor * pow(max(dot(viewDir, reflectDir), 0.0), shininess);

    return light.ambientColor + diffuse + specular;
}

vec3 calcPointLight(PointLight light, float shininess) {
    vec3 viewDir = normalize(camera.position - pos);
    vec3 lightDir = normalize(light.position - pos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    float distance = length(light.position - pos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    vec3 ambient  = attenuation * light.ambientColor;
    vec3 diffuse  = attenuation * light.diffuseColor * diff;
    vec3 specular = attenuation * light.specularColor * spec;

    return (ambient + diffuse + specular);
}

vec3 calcSpotLight(SpotLight light, float shininess) {
    vec3 viewDir = normalize(camera.position - pos);
    vec3 result = vec3(0.0, 0.0, 0.0);
    vec3 lightDir = normalize(light.position - pos);

    float theta = dot(lightDir, normalize(-light.direction));
    float cutOff = cos(light.cutOff * M_PI / 180);

    if (theta > cutOff) {
        vec3 ambient = light.ambientColor;
        vec3 norm = normalize(normal);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = light.diffuseColor * diff;
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
        vec3 specular = light.specularColor * spec;
        float distance = length(light.position - pos);
        float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

        diffuse   *= attenuation;
        specular *= attenuation;

        return ambient + diffuse + specular;
    }

    return vec3(0.0, 0.0, 0.0);
}
)";

#endif
