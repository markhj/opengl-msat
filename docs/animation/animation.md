# Animation basics

Animations with OpenGL require a [Blueprint](blueprint.md) which expresses how a property, such as ``Vec3`` changes with the progression
from 0% to 100%.

Next, an instance of ``Animation`` connects the timer, blueprint and properties which are to be
manipulated by the animation.

## Creating a Blueprint
An ``AnimationBlueprint`` is defined by "steps". You decide at which range in a percetnage
a step is applied. You can add as many steps as needed. Steps cannot overlap.

Here's an example with a single step:

````c++
AnimationBlueprint<Vec3> blueprint;
blueprint.step(0.0, 100.0, [](float pct) {
    return Vec3(sin(pct * 0.2), 0.0, cos(pct * 0.2));
});
````

For more information, please see: [Blueprint](blueprint.md).

## Animating it
An ``Animation`` instance references a timer, a blueprint and any number
of properties the manipulation should be applied on.

Imagine we have a cube and want to animate its ``translation`` property.

````c++
Object3D cube = Cube(Vec3(0.5));

Animation<Vec3> anim(&timer, &blueprint, {&cube.translate});
````

## Rendering
When it's time for the animation to start, you call:

````c++
anim.start();
````

This can be done prior to the rendering loop or inside it.

For each iteration in the rendering loop, you should call the ``tick`` function.

````c++
anim.tick();
````

This updates the referenced properties, in this case ``cube.translation``.

However, at this point the updated vertices are not yet uploaded to the ``VBO``.

Depending on how your VBO is configured and set up, there are different ways to do this.

If you use a [VBO-managed scene](../vertex/vbo-scene.md), you could use this:

````c++
vbo.upload({&cube});
````
