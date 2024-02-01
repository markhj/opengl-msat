# Shapes

The ``Shape2D`` and ``Shape3D`` classes are (still somewhat primitive) ways of organizing vertices into more
complete shapes, such as cubes.

## Role
The ``ShapeXD`` is a class that sits underneath shapes such as ``Cube``, ``Rectangle2D`` and ``Rectangle3D``.

It behaves as an abstract class (although that isn't a strict necessity, but it can't form any
vertices from a public perspective).

Extending classes can use the ``addVertex`` and ``addVertices`` methods from inside the class'es
own scope.

## Methods
````c++
std::vector<GLfloat> getVerticesFlattened(const std::vector<VertexAttribute> attributes);

std::vector<VertexElement3D> getVertices();
````

## Casting to ``ObjectXD``
Instances of ``Shape2D`` and ``Shape3D`` can be cast to ``Object2D`` and ``Object3D`` respectively.

This works for instance on the [Cube class](3d-shapes.md).

````c++
Object3D cube = Cube(Vec3(1.0));
````

Or on ``Rectangle2D``:
````c++
Object2D rect = Rectangle2D(Vec2(0.5), Vec2(0.7));
````

And that means you can now apply the various transforms on it:

````c++
cube.translate = Vec3(3.0, 0.0, 0.0);
cube.scale = 2.0;
````

## See also
* [List of 2D shapes](2d-shapes.md)
* [List of 3D shapes](3d-shapes.md)