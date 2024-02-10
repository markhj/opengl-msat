# 🎥 Camera

The ``Camera`` class keeps track of a camera's properties,
settings and assists with calculating its behavior and state.

## 📹 Initialize
````c++
Camera camera;
````

## 📌 Properties
| Property     | Data type | Default value   | Description           |
|--------------|-----------|-----------------|-----------------------|
| ``position`` | ``Vec3``  |  ``(0, 0, 0)``  | Position in 3D space  |
| ``target``   | ``Vec3``  |  ``(0, 0, -1)`` | Target ("looking at") |
| ``up``       | ``Vec3``  |  ``(0, 1, 0)``  | Which direction is up |
| ``fov``      | ``float``   |  ``45`` (&deg;) | Field of view         |
| ``zNear``    | ``float``   |  ``0.1``        | Clipping plane - near |
| ``zFar``       | ``float``   |  ``100``        | Clipping plane - far  |

## See also
* [Projections](projections.md)

