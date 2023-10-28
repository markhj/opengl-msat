# Framebuffer attachments

In [Framebuffers](fbo.md) there are different types of attachments.

When you need to specify one which isn't "Color 0", for example a depth component,
you specify it as the second parameter of the ``attach`` method.

````c++
fbo.attach(&fboTexture, FramebufferAttachment::Depth);
````

See [list of framebuffer attachments](../lists/framebuffer-enums.md).

## Multiple attachments
Furthermore, you can attach multiple textures to a framebuffer.

````c++
Texture2D fboTexture(window.getHeight(), window.getHeight());
Texture2D fboDepth(window.getHeight(), window.getHeight());

fbo.attach(&fboTexture);
fbo.attach(&fboDepth, FramebufferAttachment::Depth);
````

In this example, we have attached both a color and depth attachment to the framebuffer.
