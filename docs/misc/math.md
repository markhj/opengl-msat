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

### Calculate tangent and bi-tangent
For instance when working with [normal mapping](../lights/normal-mapping.md), you'll need to calculate
tangent and bi-tangent. These two methods can help with that.

````c++
Vec3 Math::calculateTangent(VertexElement3D a, VertexElement3D b, VertexElement3D c)
Vec3 Math::calculateBitangent(VertexElement3D a, VertexElement3D b, VertexElement3D c)
````