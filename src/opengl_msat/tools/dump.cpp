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
