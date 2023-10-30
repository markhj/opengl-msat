# Shapes

The ``Shape3D`` class is a (still somewhat primitive) way of organizing vertices into more
complete shapes, such as cubes.

## Role
The ``Shape3D`` is a class that sits underneath shapes such as ``Cube``.
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