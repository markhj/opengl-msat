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

## Signals
The free-flying camera responds to these signals:

- ``ControlSignals::MoveForward``
- ``ControlSignals::MoveBackward``
- ``ControlSignals::MoveLeft``
- ``ControlSignals::MoveRight``

## Properties
| Property  | Data type | Default | Description                                                           |
|-----------| --- |---------|-----------------------------------------------------------------------|
| ``speed`` | ``float`` | ``1.5`` | The units moved in any direction per second, while signals are active |
| ``cursorSensitivity`` | ``float`` | ``10``  | How fast the cursor moves. Lower value is slower.                     |
