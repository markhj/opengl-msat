# Math

The ``Math`` class contains basic but commonly used mathematical operations
in OpenGL.

## Functions
### Calculate normal
Calculate the normal (perpendicular vector) to three vertices.
````c++
Vec3 calculateNormal(Vec3 a, Vec3 b, Vec3 c)
````

Examle:
````c++
Vec3 normal = Math::calculateNormal(a, b, c);
````