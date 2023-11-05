# Free-Flying Camera

One of the pre-fabricated ``InputControllerRole`` is a free-flying camera
where the mouse changes the orientation of the camera, and then you can move
forward, backward, left and right.

## Setting up
To instantiate a free-flying camera, do the following:

````c++
FreeFlyingCamera ffc(&camera, &timer);

inputController.attach(&ffc);
````

## Centering the cursor
In many use-cases, it makes sense to center the cursor after each render iteration.

Use the method ``Window::centerCursor`` for this.

````c++
renderer.loop([&](Renderer* renderer) {
    // ...
    
    window.centerCursor();
});
````

## Signals
The free-flying camera responds to these signals:

- ``ControlSignals::MoveForward``
- ``ControlSignals::MoveBackward``
- ``ControlSignals::MoveLeft``
- ``ControlSignals::MoveRight``

## Properties
| Property              | Data type | Default             | Description                                                                                             |
|-----------------------| --- |---------------------|---------------------------------------------------------------------------------------------------------|
| ``speed``             | ``float`` | ``1.5``             | The units moved in any direction per second, while signals are active                                   |
| ``cursorSensitivity`` | ``float`` | ``10``              | How fast the cursor moves. Lower value is slower.                                                       |
| ``maxVerticalAngle``  | ``float`` | ``1.48`` (~85&deg;) | The maximum angle the camera can look up/down. When left at 90&deg; it can produce undesirable behavior |

## Methods
### ``setOrientation``
Set the current orientation of the camera (in radians).

````c++
void setOrientation(float horizontal, float vertical);
````

Example:
````c++
ffc.setOrientation(M_PI / 2, 0.0);
````