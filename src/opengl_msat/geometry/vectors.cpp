#include "opengl_msat/geometry/vectors.hpp"

glm::vec2 Vec2::toGlm() const
{
    return static_cast<glm::vec2>(*this);
}

glm::vec3 Vec3::toGlm() const
{
    return static_cast<glm::vec3>(*this);
}
