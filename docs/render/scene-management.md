# Scene management

To ease the management of a scene in OpenGL MSAT, you can use the ``Scene3D`` class.

The idea is that you attach a number of [objects](../geometry/object-xd.md).
The scene will then take over the responsibility of updating the objects in each
render loop iteration.

## Setting up
````c++
std::vector<Object3D*> objects = { /* Add pointers to objects relevant to scene */ };

Scene3D scene(objects);
````

## Next steps
To take the scene management to the next level, have a look at [VBO-managed scenes](../vertex/vbo-scene.md). 