#ifndef OPENGL_MSAT_CAMERA_ROLES_HPP
#define OPENGL_MSAT_CAMERA_ROLES_HPP

#include "camera.hpp"
#include "opengl_msat/timer/timer.hpp"

/**
 * Free-flying camera
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/controls/ffc/
 */
class FreeFlyingCamera : public InputControllerRole {
public:
    FreeFlyingCamera(Camera* camera, Timer* timer);

    float speed = 1.5,
        cursorSensitivity = 10.0;

    void handle(SignalList signals) override;

    void onMouseMove(CursorMoved cursorMoved) override;

private:
    Camera* camera;

    Timer* timer;

    float directionHorizontal = 0.0,
        directionVertical = 0.0;

};

#endif
