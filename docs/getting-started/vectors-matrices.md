# Vectors and matrices

## Vectors and matrices
In the ``geometry/vectors.hpp`` and ``geometry/matrices.hpp``
you find a number of useful vector/matrix classes.

We aren't going to dive too deep into them in this chapter.
We will briefly demonstrate some commonly needed operations, and explain
the relationship of the classes to GLM (OpenGL Math).

## Constructor
### ``Vec2``
````c++
// Normal
Vec2 a(1.0, 5.0);

// Scalar (all coordinates get same value)
Vec2 a(3.0);
````
### ``Vec3``
````c++
// Normal
Vec3 a(1.0, 5.0, -3.0);

// Scalar (all coordinates get same value)
Vec3 a(3.0);
````

## Operations
### Addition and subtraction
````c++
Vec3 a(1.0), b(3.0);

// Addition
Vec3 c = a + b;

// Subtraction
Vec3 d = a - b;
````
### Multiply and subtract
````c++
Vec3 a(1.0);
Vec3 b = a * 3;
````

## GLM derivatives
The vector and matrix classes contained in OpenGL MSAT are children
of GLM equivalents.

For now, they work as wrappers and don't provide any functional by themselves.

### Classes
We will gradually introduce more vector and matrix classes based on GLM
as they are needed.

| Class name | Description          | GLM parent    |
|------------|----------------------|---------------|
| ``Vec2``   | 2-dimensional vector | ``glm::vec2`` |
| ``Vec3``   | 3-dimensional vector | ``glm::vec3`` |
| ``Mat4``   | 4x4 matrix           | ``glm::mat4`` |

You initialize, work and access them similar to how you'd do in GLM.

### GLM operations
You can use GLM's mathemtical functions on these classes as well.

This means that you can for example normalize a vector like this.

````c++
Vec3 msatVector(3.0);
Vec3 normalized = glm::normalize(msatVector);
````
