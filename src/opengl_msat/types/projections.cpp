#include "opengl_msat/types/projections.hpp"

Projection::Projection(Window *window, Camera *camera) : window(window), camera(camera)
{

}

Projection &Projection::orthographic()
{
    type = ProjectionType::Orthographic;
    return *this;
}

Projection &Projection::perspective()
{
    type = ProjectionType::Perspective;
    return *this;
}

Mat4 Projection::getView() const
{
    return glm::lookAt(camera->position,
                       camera->target,
                       camera->up);
}

Mat4 Projection::getProjection() const
{
    switch (type) {
        case ProjectionType::Perspective:
            return glm::perspective(
                    glm::radians(camera->fov),
                    window->getAspectRatio(),
                    camera->zNear,
                    camera->zFar);
        case ProjectionType::Orthographic:
            return glm::ortho(0.0f,
                              static_cast<float>(window->getWidth()),
                              0.0f,
                              static_cast<float>(window->getHeight()),
                              0.0f,
                              1.0f);
        default:
            return Mat4(1.0);
    }
}

Mat4 Projection::calculate() const
{
    if (type == ProjectionType::Orthographic) {
        return getProjection();
    }
    return getProjection() * getView();
}
