#include <glm/geometric.hpp>
#include "opengl_msat/math/math.hpp"

Vec3 Math::calculateNormal(Vec3 a, Vec3 b, Vec3 c)
{
    return Vec3(-1.0, 0.0, 0.0);
    return glm::normalize(glm::cross(b - a, c - a));
}
