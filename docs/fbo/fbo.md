# Framebuffer

Framebuffers are used for a wide array of techniques, such as shadow mapping,
and rendering the same scene from multiple angles.

## Prerequisites
* [Textures](../textures/textures.md)

## Usage
A ``Framebuffer`` needs a width and height. The correct values for this
depend entirely on what you're doing with the framebuffer.

You will also need to generate a texture the framebuffer can render to.

````c++
Framebuffer fbo(window.getWidth(), window.getHeight());
Texture2D fboTexture(window.getHeight(), window.getHeight());
````

Next, we attach the texture to the buffer.
You can explore [framebuffer attachments](attachments.md) in depth,
as it's needed for [depth mapping](depth-mapping.md) among other things.

````c++
fbo.attach(&fboTexture);
````

Don't forget to bind the texture to a texture unit, in order to
be able to render it with your shader.

````c++
tum.bindTextureTo(4, &fboTexture);
````

Last, you should add a piece of code to your render loop, where
you render something that's specific to the framebuffer.

````c++
fbo.use([&]() {
    // Render contents to the framebuffer
});
````

Now, the ``fboTexture`` contains whatever has been rendered in the code above.

## Outputting content

There are different ways of outputting or using the contents of the rendered texture.
It depends entirely on the use-case.
But in many cases, you can use the [Screen quad](screen-quad.md) class to display (and debug) it.