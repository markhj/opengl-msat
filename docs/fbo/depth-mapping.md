# Depth mapping

You can create a depth map using [framebuffers](fbo-mng.md).

## Prerequisites
* [Framebuffers](fbo-mng.md)
* [Attachments](attachments.md)

## Setting up

> In this example, we demonstrate how to do the depth map in isolation. Sometimes you may want to do both color and depth.
> Please read the chapter on [attachments](attachments.md) for more information.
 
To create depth mapping, for instance for use in shadow calculations, you
create a texture to contain the mapping, and then attach it with the ``FramebufferAttachment::Depth`` argument.

````c++
Texture2D depthMapTexture(window.getHeight(), window.getHeight());

fbo.attach(&depthMapTexture, FramebufferAttachment::Depth);
````

That's actually it! Whenever you render to this framebuffer, it will now contain a black/white texture with the
depth information that fits within the near/far setting of the camera.
