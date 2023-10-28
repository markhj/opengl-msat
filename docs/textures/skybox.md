# Skybox

## Prerequisites
* [Cubemaps](cubemaps.md)

## Setting up
To set up a ``Skybox`` you first create a ``Cubemap``.
Afterwards, you inject it into ``Skybox`` together with ``Window``
and ``Camera`` objects.

````c++
CubeMap cubemap({
    "./assets/textures/skybox/right.jpg",
    "./assets/textures/skybox/left.jpg",
    "./assets/textures/skybox/top.jpg",
    "./assets/textures/skybox/bottom.jpg",
    "./assets/textures/skybox/front.jpg",
    "./assets/textures/skybox/back.jpg"
});

Skybox skybox(&cubemap, &window, &camera);
````

## Rendering

In your render loop, simply use ``Skybox::render``:

````c++
skybox.render(renderer);
````

> **Important**: In most use-cases a skybox must be rendered
> _*before*_ other content.