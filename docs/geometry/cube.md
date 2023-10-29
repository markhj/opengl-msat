# Cube

The ``Cube`` class assists in creating a basic 3-dimensional cube.

## Initializing
It's initialized by providing two vertices which are diagonally opposed.

For instance:
````c++
Cube cube(Vec3(0.0), Vec3(1.0));
````

Alternatively, you can create one where you specify only the size.
Without further manipulation (such as translations) it will be created with
its center at ``(0, 0, 0)``.

````c++
Cube cube(Vec3(1.5));
````

## Transforms

The ``Cube`` class is based on the [Shape3D class](shapes.md) which
means you have access various transform methods (translate, scale, rotate, etc.).

Read more under [Transforms](transforms.md).