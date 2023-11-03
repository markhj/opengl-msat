# Object XD

An ``Object2D`` or ``Object3D`` is a way of organizing several vertices into a group, such
that they can behave as an object.

Objects extend the ``ObjectWrapper`` class which offer a number of methods.

## Properties
You can set these properties which will then apply to all vertices of an object.

### ``Object2D``
| Property       | Data type | Default      | Description                                                   |
|----------------|-----------|--------------|---------------------------------------------------------------|
| ``translate``  | ``Vec2``  | ``Vec2(0.0)`` | Translation (moving the position)                             |
| ``rotate``     | ``float`` | ``0.0`` | Rotation (in radians)                                         |
| ``scale``      | ``float`` | ``1.0``      | Scaling                                                       |
| ``autoCenter`` | ``bool``  | ``false``    | When true, will move the basic object structure to the center |

### ``Object3D``
| Property       | Data type       | Default       | Description                                                   |
|----------------|-----------------|---------------|---------------------------------------------------------------|
| ``translate``  | ``Vec3`` | ``Vec3(0.0)`` | Translation (moving the position)                             |
| ``rotate``     | ``Vec3``        | ``Vec3(0.0)`` | Rotation around each axis (in radians)                        |
| ``scale``      | ``float``       | ``1.0``       | Scaling                                                       |
| ``autoCenter`` | ``bool``        | ``false``     | When true, will move the basic object structure to the center |

### ``autoCenter``
There are essentially two ways in OpenGL MSAT to position an object. You can define the position, size and shape
of an object using vertices, or you can define the size and shape with vertices, and then use ``translation``
to position it.

Some may prefer to separate the two. The enforce this behavior you can set ``autoCenter`` to true.

Example without using ``autoCenter``:

````c++
// Create a cube with the size of 1x1x1 and position it far away from the center
Object3D cube = Cube(Vec3(10.0, 0.0, 10.0), Vec3(9.0, 1.0, 9.0));
````

Example using ``autoCenter``:
````c++
Object3D cube = Cube(Vec3(1.0));
cube.autoCenter = true;
cube.translate = Vec3(9.0, 0.0, 9.0);
````

It's your choice whether you want to combine position and size in vertices, or if you prefer a separated
approach where vertice define the size and shape, and then apply translation to position it.

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
