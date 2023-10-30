# Animations

In this guide, we will move a cube in a circle.

## Setting up
In this example we will use the [VBO-managed scene](../vertex/vbo-scene.md).

First, we create a [Cube](../geometry/cube.md), a scene, a VAO and VBO.

````c++
Object3D cube = Cube(Vec3(-0.25, 0.11, -0.25), Vec3(0.25, 0.5, 0.25));
Scene3D scene({&cube});

VAO vao;
VBOScene3D vbo(&scene, attributes);
vao.associate(vbo, attributes);
````

## Blueprint
Next, we'll create an [animation blueprint](../animation/blueprint.md) which
"circles" its input all the way from 0% to 100%.
````c++
AnimationBlueprint<Vec3> blueprint;
blueprint.step(0.0, 100.0, [](float pct) {
    return Vec3(sin(pct * 0.2), 0.0, cos(pct * 0.2));
});
````

## Animation
Now, we create the actual animation object, and reference the cube's translation property, since
we want it to _move_ in a circle.

````c++
Animation<Vec3> animation(&timer, &blueprint, {&cube.translate});
````

> You can reference multiple properties, also rotation or scale, for instance.

## Rendering
Just before the render loop, we start the animation.

We also need to "tick" the animation within the loop - this will update the properties.

And last, we have to remember to upload the updated vertices to the VBO.

````c++
animation.start();

renderer.loop([&](Renderer* renderer) {
    // Initial render code

    animation.tick();

    vbo.upload({&cube});

    // Rest of rendering
});
````

## That's all

With this, you should see a cube moving in a circle.