#include "opengl_msat/geometry/matrices.hpp"

glm::mat4 Mat4::toGlm() const {
    return static_cast<glm::mat4>(*this);
}
