#include "opengl_msat/tools/dump.hpp"
#include <iostream>

void Dump::dump(Mat4 value)
{
    glm::mat4 a = value.toGlm();
    for (int i = 0; i <= 3; i++) {
        std::cout << "[ ";
        for (int j = 0; j <= 3; j++) {
            std::cout << a[i][j] << (j < 3 ? " , " : " ");
        }
        std::cout << "]\n";
    }
    std::cout << std::endl;
}

void Dump::dump(Vec4 value)
{
    std::cout << "{ " << value.x << " , " << value.y << " , " << value.z << " , " << value.w << " }";
}

void Dump::dump(Vec3 value)
{
    std::cout << "{ " << value.x << " , " << value.y << " , " << value.z << " }";
}

void Dump::dump(Vec2 value)
{
    std::cout << "{ " << value.x << " , " << value.y << " }";
}

void Dump::dump(SystemInfo systemInfo)
{
    std::string result = "SYSTEM INFO";

    result += dumpTitle("OpenGL");
    result += cell("Version", std::to_string(systemInfo.openGLVersion.major) + "." + std::to_string(systemInfo.openGLVersion.minor));
    result += cell("Full version", systemInfo.openGLVersion.version);

    result += dumpTitle("GPU");
    result += cell("Name", systemInfo.gpu.name);
    result += cell("Vendor", systemInfo.gpu.vendor);
    result += cell("Driver", systemInfo.gpu.driverVersion);

    result += dumpTitle("Textures");
    result += cell("Texture units", std::to_string(systemInfo.maxTextureUnits));
    result += cell("Max. texture size", std::to_string(systemInfo.maxTextureSize));
    result += cell("Max. 3D texture size", std::to_string(systemInfo.maxTextureSize3D));
    result += cell("Max. cubemap texture size", std::to_string(systemInfo.maxTextureSizeCubemap));

    result += dumpTitle("Framebuffers");
    result += cell("Max. framebuffers", std::to_string(systemInfo.maxFramebuffers));
    result += cell("Max. dimensions", std::to_string(systemInfo.framebufferMaxWidth) + " x " + std::to_string(systemInfo.framebufferMaxHeight));

    result += dumpTitle("Misc.");
    result += cell("Max. uniform locations", std::to_string(systemInfo.maxUniformLocations));

    std::cout << result << std::endl;
}

std::string spacing(std::string input, int max)
{
    std::string result = input;

    if (input.length() > max) {
        return input.substr(0, max - 3) + "...";
    }

    for (int i = 0; i < max - input.length(); i++) {
        result += " ";
    }
    return result;
}

std::string Dump::dumpTitle(std::string title)
{
    std::string bar = "-------------------------------------------------------------------------";
    return "\n\n" + /*bar + "\n  " +*/ title + "\n" + bar;
}

std::string Dump::cell(std::string title, std::string value)
{
    return "\n| " + spacing(title, 30) + " | " + spacing(value, 36) + " |";
}

void Dump::dump(std::optional<Mat4> value)
{
    if (value.has_value()) {
        dump(value.value());
    } else {
        printNoValue("Mat4");
    }
}

void Dump::dump(std::optional<Vec4> value)
{
    if (value.has_value()) {
        dump(value.value());
    } else {
        printNoValue("Vec4");
    }
}

void Dump::dump(std::optional<Vec3> value)
{
    if (value.has_value()) {
        dump(value.value());
    } else {
        printNoValue("Vec3");
    }
}

void Dump::dump(std::optional<Vec2> value)
{
    if (value.has_value()) {
        dump(value.value());
    } else {
        printNoValue("Vec2");
    }
}

void Dump::printNoValue(std::string type)
{
    std::cout << type << " { Optional without value }" << std::endl;
}
