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

    result += dumpTitle("GPU");
    result += cell("Name", systemInfo.gpu.name);
    result += cell("Vendor", systemInfo.gpu.vendor);
    result += cell("Driver", systemInfo.gpu.driverVersion);

    result += dumpTitle("Textures");
    result += cell("Texture units", std::to_string(systemInfo.maxTextureUnits));

    std::cout << result << std::endl;
}

std::string Dump::dumpTitle(std::string title)
{
    return "\n\n" + title + "\n------------------------------";
}

std::string Dump::cell(std::string title, std::string value)
{
    return "\n" + title + " : " + value;
}
