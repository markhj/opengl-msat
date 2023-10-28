#ifndef OPENGL_MSAT_PROJECTIONS_HPP
#define OPENGL_MSAT_PROJECTIONS_HPP

#include <iostream>
#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/window/window.hpp"
#include "opengl_msat/camera/camera.hpp"

/**
 * Project type
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/projections/
 */
enum class ProjectionType {
    None,
    Orthographic,
    Perspective
};

/**
 * Projection
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/camera/projections/
 */
class Projection {
public:
    ProjectionType type = ProjectionType::None;

    Projection(Window* window, Camera* camera);

    Projection& orthographic();

    Projection& perspective();

    [[nodiscard]] Mat4 getView() const;

    [[nodiscard]] Mat4 getProjection() const;

    [[nodiscard]] Mat4 calculate() const;

    Camera* getCamera() const;

private:
    Window* window;

    Camera* camera;

};

#endif
