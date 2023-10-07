#include "opengl_msat/geometry/vectors.hpp"

glm::vec2 Vec2::toGlm() const
{
    return static_cast<glm::vec2>(*this);
}

void Vec2::animate(float pct, Vec2 from, Vec2 to)
{
    x = from.x + pct * (to.x - from.x) / 100;
    y = from.y + pct * (to.y - from.y) / 100;
}

void Vec2::animate(Vec2 value)
{
    x = value.x;
    y = value.y;
}

glm::vec3 Vec3::toGlm() const
{
    return static_cast<glm::vec3>(*this);
}

void Vec3::animate(float pct, Vec3 from, Vec3 to)
{
    x = from.x + pct * (to.x - from.x) / 100;
    y = from.y + pct * (to.y - from.y) / 100;
    z = from.z + pct * (to.z - from.z) / 100;
}

void Vec3::animate(Vec3 value)
{
    x = value.x;
    y = value.y;
    z = value.z;
}
