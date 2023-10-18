#ifndef OPENGL_MSAT_PROJECTIONS_HPP
#define OPENGL_MSAT_PROJECTIONS_HPP

#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/window/window.hpp"
#include "opengl_msat/camera/camera.hpp"

enum class ProjectionType {
    None,
    Orthographic,
    Perspective
};

class Projection {
public:
    ProjectionType type = ProjectionType::None;

    Projection(Window* window, Camera* camera) : window(window), camera(camera) { }

    Projection& orthographic()
    {
        type = ProjectionType::Orthographic;
        return *this;
    }

    Projection& perspective()
    {
        type = ProjectionType::Perspective;
        return *this;
    }

    [[nodiscard]] Mat4 getView() const
    {
        return glm::lookAt(camera->position,
                           camera->target,
                           camera->up);
    }

    [[nodiscard]] Mat4 getProjection() const
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
                    static_cast<float>(window->getHeight()),
                    0.0f,
                    camera->zNear,
                    camera->zFar);
            default:
                return Mat4(1.0);
        }
    }

    [[nodiscard]] Mat4 calculate() const
    {
        return getProjection() * getView();
    }

private:
    Window* window;

    Camera* camera;

};

#endif
