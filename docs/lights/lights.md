# Light basics

## Prerequisites
* [Fragment Shader Builder](../shader/fragment-shader-builder.md)
* [Shader uniforms](../shader/uniform.md)

## Introduction
With the _Fragment Shader Builder_ is fairly easy to implement simple lights.

OpenGL MSAT supports three basic types:

- [Directional light](directional.md)
- [Point light](point-light.md)
- [Spot light](spot-light.md)

There are some common threads to implementing each of these.

## Setting up

First things first: The Fragment Shader Builder must have lights enabled.

````c++
FragmentShaderBuilder fsb(vertexAttributes);

fsb.lighting();
````

## Slots
Additionally, you may want to configure the number of slots. This is the number
of lights which will be created for each type of light in the shader uniform array.

````c++
fsb.lightSlots = 100;
````

This must be configured at any point before building the shader's source code.

## Usage

In this example, we will create a [point light](point-light.md):
````c++
PointLight pointLight {
    .position = Vec3(0.5, 0.3, 0.5),
    .ambientColor = Color(0.1),
    .diffuseColor = Color(0.8, 0.2, 0.8),
    .specularColor = Color(0.8, 0.2, 0.8)
};
````
All lights start out as simple structs like the one seen above.

Next, you have to define two shader uniform values:

* ``numPointLights`` which specifies the exact amount of point lights. It's important to get this value right, as setting it too high means the light calculations could fail.
* ``pointLights`` which is the array with the actual point light specific data such as position and color.

````c++
shader.uniform("numPointLights", 1);
shader.uniform("pointLights", 0, pointLight);
````
In this example we have just a single point light, and its data is added at what corresponds to ``pointLights[0]``.

If your shader and the data is otherwise set up correctly, this is all it takes to add light.

## Dynamic updates

You can dynamically update the light properties in the render loop.
Simply, make the required changes and set the data again.

````c++
Timer timer;
float t = 0.0;

renderer.loop([&](Renderer* renderer) {
    // ...
    t += timer.getDeltaTime();
    // ...
    pointLight.position = Vec3(sin(t), 1.0, cos(t));
    shader.uniform("pointLights", 0, pointLight);
    // ...
});
````
In this example the point light will fly in a circle.

## See also
* [Helper](../tools/helper.md) - How to track lights on the scene