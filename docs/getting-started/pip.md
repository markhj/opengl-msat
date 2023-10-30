# Picture-in-picture

In this guide we will demonstrate [framebuffers](../fbo/fbo.md) and [screen quads](../fbo/screen-quad.md)
by creating a picture-in-picture scene.

For this example, we recommend setting up a simple scene, maybe where a camera
rotates around a cube.

## Setting up

We start by initializing a framebuffer named ``fbo`` and two textures.

One texture we will use for the colors of the rendering, and the other contains
depth information.

````c++
Framebuffer fbo(window.getWidth(), window.getHeight());
Texture2D fboTexture(window.getHeight(), window.getHeight());
Texture2D fboDepth(window.getHeight(), window.getHeight());
````

Next, we attach the two textures to the framebuffer, and bind the color-texture
to unit 4. You can choose another unit, if you want.
````c++
fbo.attach(&fboTexture);
fbo.attach(&fboDepth, FramebufferAttachment::Depth);

tum.bindTextureTo(4, &fboTexture);
````

> The reason we include the depth component, is that without it, the scene may render
> differently, because OpenGL lacks information about Z-axis of the vertices.

## Initialize screen quad
The ``ScreenQuad`` will display the texture rendered by the framebuffer.

````c++
ScreenQuad screenQuad(&window, &camera, Vec2(15.0), Vec2(300.0, 200.0), &fboTexture);
````

The quad is position in the bottom-left corner, and has a size of 300 x 200.

## Rendering
In the frambuffer-specific part you could make the camera go in the opposite direction,
being static, or any other number of things. You can also leave it as-is and simple render the exact
identical scene into the framebuffer.

````c++
renderer.loop([&](Renderer* renderer) {
    fbo.use([&]() {
        // Render picture-in-picture content
        
        renderer->render(vao);
    });

    // Put your normal rendering here
    renderer->render(vao);

    screenQuad.render(renderer);
});
````
