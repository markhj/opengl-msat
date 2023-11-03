# Dump objects

The ``Dump`` class can easily write information about a number
of classes to the console.

## Support
It currently supports:

- ``Vec2``, ``Vec3``, ``Vec4``
- ``Mat4``
- ``SystemInfo``
- ``std::vector<GLfloat>``
- ``Object2D``, ``Object3D``

### ``std::vector<GLfloat>``
There are three relevant signatures for dumping ``std::vector<GLfloat>``:

````c++
void dump(std::vector<GLfloat> values);
void dump(std::vector<GLfloat> values, unsigned int perRow);
void dump(std::vector<GLfloat> values, std::vector<VertexAttribute> attributes);
````

These makes it easier to dump vectors with ``GLfloat`` - often that would be your (final/flattened)
list of numbers which up the vertices you're uploading to the VBO.

Example:
````c++
std::vector<VertexAttribute> attributes = {
        VertexAttribute::Position2D,
        VertexAttribute::ColorRGB
};

Object2D triangle;
triangle.add({
    // List of vertices
});

Dump::dump(triangle.getVerticesFlattened(attributes));
````

## Usage
You can dump an object with:

````c++
Vec3 vec3(1.0, 2.0, 3.0);

Dump::dump(vec3);
````

## Optionals

``Dump::dump`` will also accept ``std::optional<T>`` where
``T`` can be the following types:

- ``Vec2``, ``Vec3``, ``Vec4``
- ``Mat4``

This is useful, for instance when working with certain attributes
of the ``VertexElementXD`` class.

When the optional has no value, this will instead be printed to the console.

Example:

````c++
std::optional<Vec3> optionalVec3;
Dump::dump(optionalVec3);  // Will print "Optional wihtout value"

optionalVec3 = Vec3(1.0);
Dump::dump(optionalVec3);  // Will print "{ 1, 1, 1 }"
````
