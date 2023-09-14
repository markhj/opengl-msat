#include <iostream>
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

void Camera::setPosition(Vec3 value)
{
    position = value;
}

void Camera::setTarget(Vec3 value)
{
    target = value;
}

void Camera::setClippingPlane(float near, float far)
{
    zNear = near;
    zFar = far;
}

void Camera::setFieldOfView(float deg)
{
    fov = deg;
}
