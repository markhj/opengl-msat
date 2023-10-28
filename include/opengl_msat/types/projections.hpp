#ifndef OPENGL_MSAT_PROJECTIONS_HPP
#define OPENGL_MSAT_PROJECTIONS_HPP

#include <iostream>
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

    Projection(Window* window, Camera* camera);

    Projection& orthographic();

    Projection& perspective();

    [[nodiscard]] Mat4 getView() const;

    [[nodiscard]] Mat4 getProjection() const;

    [[nodiscard]] Mat4 calculate() const;

private:
    Window* window;

    Camera* camera;

};

#endif
