# 🐣 Models

You can load Wavefront (.obj) models with the ``Model`` class.

````c++
Model model("path/to/model.obj");
````

## 🔨 Generating mesh
To generate the mesh, you simply call:

````c++
model.load();
````

The mesh is now stored in a ``Object3D`` instance contained within
the ``Model`` object.

To extract it, you use:

````c++
Object3D modelAsObject = model.toObject();
````

You can shorthand all this to:

````c++
Object3D modelAsObject = model("path/to/model.obj").load().toObject();
````

## 📌 Example
This example assumes usage of [VBO-managed scene](../vertex/vbo-scene.md).

````c++
Object3D model = model("path/to/model.obj").load().toObject();

Scene3D scene({ &model });

VAO vao;
VBOScene3D vbo(&scene, attributes);
vao.associate(vbo, attributes);

renderer.loop([&](Renderer* renderer) {
    // Render code
    
    renderer->render(vao);
    
    // Render code
});
````

