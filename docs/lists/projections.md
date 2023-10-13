# Projections
The ``Projection`` enumeration is used in various places in the code,
such as in [Camera](../camera/camera.md) and [shader builders](../getting-started/shader-builders.md) to
ensure appropriate calculations and structures.

## Enumerations

| Value | Description                                 |
| --- |---------------------------------------------|
| ``Projection::None`` ´| No perspective calculations will be applied |
| ``Projection::Perspective`` | 3D/perspective |
| ``Projection::Orthographic`` | Orthographic |