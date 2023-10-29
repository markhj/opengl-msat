# Helper

The ``Helper`` assists with tools for visual debugging.
For instance, it can indicate where the center of a light is, or its direction.

## Setting up
Initialize the ``Helper`` class with:

````c++
Helper helper(&window, &camera);
````

In your render loop, you add:

````c++
helper.render(renderer);
````

## Tracking lights

There's currently support for [point lights](../lights/point-light.md) and
[spot lights](../lights/spot-light.md).

Simply call the helper's ``track`` method with the light as the argument. For example:

````c++
helper.track(&pointLight);
````

Now, whenever the helper is rendered, it display a dot at the center of the
point light colored in the light's diffuse color.