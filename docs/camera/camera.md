# Camera

The ``Camera`` class keeps track of a camera's properties,
settings and assists with calculating its behavior and state.

## Include and initialize
Include with:

````c++
#include <opengl_msat/camera/camera.hpp>
````

The camera must be provided instance of [Window](../window/window.md) upon 
initialization:

````c++
Camera camera(window);
````

## Default settings
| Setting               | Default value  |
|-----------------------|----------------|
| Position              | ``(0, 0, 0)``  |
| Target                | ``(0, 0, -1)`` |
| Up                    | ``(0, 1, 0)``  |
| Field of view         | ``45`` (&deg;) |
| Clipping plane - near | ``0.1``        |
| Clipping plane - far  | ``100``        |

## Changing settings
You can modify the settings listed above with a number of setters:

````c++
void setPosition(Vec3 value);

void setTarget(Vec3 value);

void setFieldOfView(float deg);

void setClippingPlane(float near, float far);
````

## Calculations
The ``Camera`` class can aid with calculating model, view and projection.

Simply use these functions:

````c++
Mat4 getModel() const;

Mat4 getView() const;

Mat4 getProjection() const;
````

