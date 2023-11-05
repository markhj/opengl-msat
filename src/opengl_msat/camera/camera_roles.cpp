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

IsometricCamera::IsometricCamera(Window* window, Camera *camera, Timer *timer)
    : window(window), camera(camera), timer(timer)
{

}

void IsometricCamera::handle(SignalList signals)
{
    float moveSpeed = speed * timer->getDeltaTime();

    // If a rotation is active we'll call rotationAnimation and stop execution
    // of the remainder of the method
    if (rotationTargetAngle.has_value()) {
        rotationAnimation();
        return;
    }

    rotation(signals);

    // Adjust the height (if requested)
    if (heightAdjustable && signals.has(ControlSignals::MoveUp) && height < maxHeight) {
        height += moveSpeed;
    } else if (heightAdjustable && signals.has(ControlSignals::MoveDown) && height > minHeight) {
        height -= moveSpeed;
    }

    // Set the initial signals
    bool moveForward = signals.has(ControlSignals::MoveForward);
    bool moveBackward = signals.has(ControlSignals::MoveBackward);
    bool moveLeft = signals.has(ControlSignals::MoveLeft);
    bool moveRight = signals.has(ControlSignals::MoveRight);

    // Check if the cursor can affect the moveX values set above
    if (moveWithMouse && cursorPos.has_value()) {
        Vec2 curPos = cursorPos.value();

        if (curPos.y <= cursorToBorderMargin) {
            moveForward = true;
        } else if (curPos.y >= window->getHeight() - cursorToBorderMargin) {
            moveBackward = true;
        }

        if (curPos.x <= cursorToBorderMargin) {
            moveLeft = true;
        } else if (curPos.x >= window->getWidth() - cursorToBorderMargin) {
            moveRight = true;
        }
    }

    // Create a 2-dimensional vector which will be set according to the
    // movements defined above
    Vec2 mv(0.0);

    if (moveForward) {
        mv.y = 1.0;
    } else if (moveBackward) {
        mv.y = -1.0;
    }

    if (moveLeft) {
        mv.x = 1.0;
    } else if (moveRight) {
        mv.x = -1.0;
    }

    // Take the currently defined orientation angle and add the angle defined
    // by the desired movements above
    float calculatedAngle = angle + glm::atan(mv.x, mv.y);

    // If movement is requsted, we add the values to the current camera position
    if (mv.x != 0 || mv.y != 0) {
        camera->position.x += moveSpeed * sin(calculatedAngle);
        camera->position.z += moveSpeed * cos(calculatedAngle);
    }

    // Set the target according to the camera position, the defined height and
    // the angle of the orientation - this ensures the fixed relationship between
    // camera and target required for it to isometric
    camera->target.x = camera->position.x + height * sin(angle);
    camera->target.z = camera->position.z + height * cos(angle);

    // Set the height relationship between camera and target
    camera->position.y = offsetY + height;
    camera->target.y = offsetY;
}

void IsometricCamera::onMouseMove(CursorMoved cursorMoved)
{
    cursorPos = Vec2(cursorMoved.x, cursorMoved.y);
}

void IsometricCamera::rotationAnimation()
{
    float to = rotationTargetAngle.value();

    if (abs(to - angle) < 0.005) {
        angle = to;
        rotationTargetAngle = std::nullopt;
    } else {
        angle += (to > angle ? 1 : -1) * rotationSpeed * timer->getDeltaTime();
        if (rotationMode == IsometricCameraRotation::AroundCamera) {
            camera->target.x = camera->position.x + height * sin(angle);
            camera->target.z = camera->position.z + height * cos(angle);
        } else if (rotationMode == IsometricCameraRotation::AroundTarget) {
            camera->position.x = camera->target.x + height * sin(angle + M_PI);
            camera->position.z = camera->target.z + height * cos(angle + M_PI);
        }
    }
}

void IsometricCamera::rotation(SignalList signals)
{
    if (!allowRotation) {
        return;
    }

    if (signals.has(ControlSignals::RotateCW)) {
        rotationTargetAngle = angle + M_PI / 2;
    } else if (signals.has(ControlSignals::RotateCCW)) {
        rotationTargetAngle = angle - M_PI / 2;
    }
}
