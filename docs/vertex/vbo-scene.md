# VBO managed scene

The ``VBOScene3D`` class takes the concept of scene management a step further,
by also integrating the ``VBO`` to its pipeline.

## Prerequisites
* [Scene management](../vertex/vbo-scene.md)

## Setting up
Set up a scene with a number of objects.
````c++
Object3D floor = Cube(Vec3(5.0));
Object3D staticBox = Cube(Vec3(-2.0, 0.0, -2.0), Vec3(-1.5, 1.0, -1.5));
Object3D rotatingBox = Cube(Vec3(0.25));

Scene3D scene({&floor, &staticBox, &rotatingBox});
````

Next, we initialize the [VAO](vao.md), ``VBOScene3D`` and associate them.

````c++
VAO vao;
VBOScene3D vbo(&scene, attributes);
vao.associate(vbo, attributes);
````

## Rendering
When an object has changed you can upload the modified objects with:

````c++
rotatingBox.rotation = Vec3(sin(t), 0.0, 0.0);

vbo.upload({&rotatingBox});
````

Or you can upload everything in the scene:

````c++
vbo.upload();
````

This is not recommended practice if your scene contains many unchanged objects,
as it puts unnecessary strain on the rendering pipeline.