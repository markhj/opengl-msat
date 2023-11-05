# Isometric camera

The ``IsometricCamera`` moves around on a 2D surface and retains the angular
relationship to a target on another 2D surface.

## Setting up
First, you must have set up your [InputController](input-controller.md).

Then you instantiate an isometric camera with:

````c++
IsometricCamera isometricCamera(&window, &camera, &timer);

inputController.attach(&isometricCamera);
````

## Signals
The isometric camera responds to these signals:

- ``ControlSignals::MoveForward``
- ``ControlSignals::MoveBackward``
- ``ControlSignals::MoveLeft``
- ``ControlSignals::MoveRight``

Optionally, it can respond to:

- ``ControlSignals::MoveUp`` (when ``heightAdjustable`` is enabled)
- ``ControlSignals::MoveDowm`` (when ``heightAdjustable`` is enabled)
- ``ControlSignals::RotateCW`` (when ``allowRotation`` is enabled) 
- ``ControlSignals::RotateCCW`` (when ``allowRotation`` is enabled)

## Properties
| Property              | Data type                   | Default                | Description                                                                                                                                        |
|-----------------------|-----------------------------|------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------|
| ``position``             | ``Vec2``                    | ``(0, 0)``             | The position of the camera (on 2D surface)                                                                                                         |
| ``angle`` | ``float``                   | ``M_PI / 4`` (45&deg;) | The XZ orientation of the camera                                                                                                                   |
| ``speed``  | ``float``                   | ``1.0``                | The speed of the camera                                                                                                                            |
| ``height``  | ``float``                   | ``2.0``                | The distance from the camera to the surface below                                                                                                  |
| ``heightAdjustable``  | ``bool``                    | ``true``               | Height can be adjusted with the signals ``MoveUp`` and ``MoveDown``                                                                                |
| ``offsetY``  | ``float``                   | ``0.0``                | Offset the "floor" underneath the camera                                                                                                           |
| ``maxHeight``  | ``float``                   | ``3.0``                | Max. height (when adjustable)                                                                                                                      |
| ``minHeight``  | ``float``                   | ``1.5``                | Min. height (when adjustable)                                                                                                                      |
| ``moveWithMouse``  | ``bool``                    | ``true``               | The camera can be moved when the cursor is at the edges of the window                                                                              |
| ``cursorToBorderMargin``  | ``unsigned int``            | ``5``                  | The distance to the window edges where the cursor can be (and still trigger movement)                                                              |
| ``allowRotation``  | ``bool``                    | ``true``               | Camera can be rotated with signals ``RotateCW`` (clockwise) and ``RotateCCW`` (counter-clockwise)                                                  |
| ``rotationSpeed``  | ``float``                   | ``1.0``                | The speed when the camera rotates                                                                                                                  |
| ``rotationMode``  | ``IsometricCameraRotation`` | ``AroundCamera``       | The method of rotation (for instance around camera or around target). See [Isometric camera rotation enumerations](../lists/camera-roles-enums.md) |
