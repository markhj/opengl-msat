#include "opengl_msat/camera/camera_roles.hpp"

FreeFlyingCamera::FreeFlyingCamera(Camera *camera, Timer *timer)
    : camera(camera), timer(timer)
{

}

void FreeFlyingCamera::handle(SignalList signals)
{
    float moveSpeed = timer->getDeltaTime() * speed;

    // Create a two-dimensional vector which tracks in which
    // direction the combined inputs indicate movement.
    // For instance, the combination of UP and LEFT moves diagonally
    Vec2 xzDirection(0.0, 0.0);

    // Determine the Z-axis direction (given as Y on xzDirection because it's a 2D vector)
    if (signals.has(ControlSignals::MoveForward)) {
        xzDirection.y = 1.0;
    } else if (signals.has(ControlSignals::MoveBackward)) {
        xzDirection.y = -1.0;
    }

    // Determine the movement on the X-axis
    if (signals.has(ControlSignals::MoveLeft)) {
        xzDirection.x = -1.0;
    } else if (signals.has(ControlSignals::MoveRight)) {
        xzDirection.x = 1.0;
    }

    // Take the horizontal (XZ) direction which is determined by cursor movement
    // Add this with the angle of xzDirection (subtracted 90 degrees)
    // This way we move the camera with the respect to the orientation of it
    float dh = directionHorizontal + atan2(xzDirection.y, xzDirection.x) - M_PI / 2;

    // Set the camera's position and target if there's any movement indicated by xzDirection
    if (xzDirection.x != 0 || xzDirection.y != 0) {
        camera->position.x += sin(dh) * moveSpeed;
        camera->position.z += cos(dh) * moveSpeed;
        camera->position.y += xzDirection.y * sin(directionVertical) * moveSpeed;
    }

    // Update the camera target
    // We need to update this even when no movement is indicated, because
    // cursor movement can occur without repositioning the camera
    camera->target = camera->position + Vec3(
            sin(directionHorizontal),
            tan(directionVertical),
            cos(directionHorizontal)
    );
}

void FreeFlyingCamera::onMouseMove(CursorMoved cursorMoved)
{
    float sensitivityFactor = 1000;

    directionHorizontal -= cursorMoved.diffX * cursorSensitivity / sensitivityFactor;
    directionVertical -= cursorMoved.diffY * cursorSensitivity / sensitivityFactor;

    if (directionVertical > maxVerticalAngle) {
        directionVertical = maxVerticalAngle;
    } else if (directionVertical < -maxVerticalAngle) {
        directionVertical = -maxVerticalAngle;
    }
}

void FreeFlyingCamera::setOrientation(float horizontal, float vertical)
{
    directionHorizontal = horizontal;
    directionVertical = vertical;
}
