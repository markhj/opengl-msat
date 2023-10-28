# Screen quad
The ``ScreenQuad`` class simplifies the process of displaying a texture on the screen. The quad
can either fill up a part of the screen or everything - this depends on the use-case.

## Prerequisites
* [Texture](../textures/textures.md)
* [Framebuffer](../fbo/fbo.md) (Recommended)

## Usage
A screen quad must be associated with a texture, which will be the one it renders.
This is often a texture rendered by a [Framebuffer](../fbo/fbo.md), but it doesn't have to be.

The ``ScreenQuad`` takes five parameters:

- Instance of ``Window``
- Instance of ``Camera``
- A ``Vec2`` which represents the bottom-left corner position
- A ``Vec2`` which specifies the size
- A pointer to the texture which should be rendered

````c++
Texture2D texture(window.getHeight(), window.getHeight());

// ...

ScreenQuad screenQuad(&window, &camera, Vec2(15.0), Vec2(300.0), &texture);
````

Lastly, somewhere in your render loop, add:

````c++
screenQuad.render(renderer);
````

## Relationship to framebuffers
As you may know, framebuffers render their content to textures.
The idea is that screen quads makes it easy and convenient to display
what has been rendered.
