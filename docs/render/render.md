# Rendering

The ``Renderer`` provides a number of essential and a number of optional tools
for rendering with OpenGL MSAT.

## Include
````c++
#include "opengl_msat/renderer/renderer.hpp"
````

## Setup
In its simplest form, a render loop can look like this:

````c++
// Initialize window, timer, VAO and VBO

RenderSettings renderSettings;
Renderer renderer(window, timer, renderSettings);

while (window.keepOpen()) {
    renderer.clear();
    
    renderer.render(vao);
    
    window.swapBuffers();
    window.pollEvents();
}
````

The ``Renderer::clear`` method clears color, depth and stencil buffer bits and resets the frame to black.

The ``Renderer::render`` method binds to the provided VAO and renders in standard mode (triangles and all content of associated VBO).

## Render loop (optional)

The ``Renderer`` class provides an optional ``loop`` function.

It carries out a number of trivial tasks such as lapsing the timer, clearing the display,
swapping buffers and polling events.

It can be used like this:

````c++
// Initialize window, timer, VAO and VBO

RenderSettings renderSettings;
Renderer renderer(window, timer, renderSettings);

renderer.loop([&](Renderer* renderer) {
    renderer->render(vao);
});
````

As you see, the code is simpler and boilerplate has been reduced. But it requires a slightly different way of thinking about
the structure of your code, because it uses a lambda function.

## Customized rendering

As mentioned earlier, the ``Renderer::render`` method assumes
you want to render triangles and the entire content of the VBO.

But there are a few other methods in case you want to change that behavior.

The three ``render`` methods are:

````c++
void render(VAO& vao);

void render(VAO vao, DrawMode drawMode);

void render(VAO& vao, DrawMode drawMode, unsigned int from, unsigned int count);
````

With these in mind, you can for example draw with points instead of triangles:

````c++
renderer.loop([&](Renderer* renderer) {
    renderer->render(vao, DrawMode::Points);
});
````

## Draw modes

The three render/draw modes are:

| Mode                    | Description                                                     |
|-------------------------|-----------------------------------------------------------------|
| ``DrawMode::Points``    | Renders singular points                                         |
| ``DrawMode::Lines``     | Renders lines (requires pairs of vertices, i.e. an even number) |
| ``DrawMode::Triangles`` | Renders triangles (requires 3 vertices for every triangle)      |

## State and settings
See chapters [Render settings](/render/render-settings) and [Render state](render/render-state)
to learn about the two.

### Temporary swap
You can temporarily swap settings and state using the methods
``swapSettings`` and ``swapState``.

At the end of the method's execution the Renderer returns to the state
it was in just prior to the ``swap*`` method being called.

This is useful when you create helper classes which need to make
changes to the render state or settings, and when you can't be certain
which state you need to return to.

````c++
RenderSettings newSettings;

renderer.swapSettings(newSettings, [&](Renderer* renderer) {
    // Do something with the new settings
});

// Settings from before swapSettings was called are now back in effect
````