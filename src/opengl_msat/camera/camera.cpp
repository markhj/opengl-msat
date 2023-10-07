#include "opengl_msat/camera/camera.hpp"

Mat4 Camera::getModel() const
{
    return Mat4(1.0);
}

Mat4 Camera::getView() const
{
    return glm::lookAt(position, target, up);
}

Mat4 Camera::getProjection() const
{
    return glm::perspective(
            glm::radians(fov),
            window.getAspectRatio(),
            zNear,
            zFar);
}
