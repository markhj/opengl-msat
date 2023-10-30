# Object XD

An ``Object2D`` or ``Object3D`` is a way of organizing several vertices into a group, such
that they can behave as an object.

Objects extend the ``ObjectWrapper`` class which offer a number of methods.

## Properties
You can set these properties which will then apply to all vertices of an object.

They take effect when using ``ObjectXD``'s methods to retrieve the contained 
vertices.

| Property      | Data type | Default       | Description                       |
|---------------|-----------|---------------|-----------------------------------|
| ``translate`` | ``Vec3``  | ``Vec3(0.0)`` | Translation (moving the position) |
| ``rotate``    | ``Vec3``  | ``Vec3(0.0)`` | Rotation around each axis         |
| ``scale``     | ``float`` | ``1.0``       | Scaling                           |

## Methods
````c++
std::vector<VertexElement3D> getVertices();
````

Returns all vertices (with applied manipulations by the translate, rotate and scale proprties).

````c++
std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes)
````
Returns the list of float values (with respect to the listed attributes).

## Casting
Instances of ``Shape3D`` can be cast to ``Object3D``.
This works for instance on the [Cube class](cube.md).

````c++
Object3D cube = Cube(Vec3(1.0));
````

And that means you can now apply the various transforms on it:

````c++
cube.translate = Vec3(3.0, 0.0, 0.0);
cube.scale = 2.0;
````
