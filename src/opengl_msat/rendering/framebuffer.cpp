#include "opengl_msat/rendering/framebuffer.hpp"


Framebuffer::Framebuffer(unsigned int width, unsigned int height) : width(width), height(height)
{
    generate();
}

void Framebuffer::attach(Texture2D *texture)
{
    attach(texture, FramebufferAttachment::Color);
}

void Framebuffer::attach(Texture2D *texture, FramebufferAttachment attachment)
{
    safeBind();

    texture->safeBind();
    glTexImage2D(GL_TEXTURE_2D,
         0,
         getFormat(attachment),
         width,
         height,
         0,
         getFormat(attachment),
         GL_UNSIGNED_BYTE,
         nullptr);

    texture->applyOptions({
        .downSampling = TextureDownsampling::Linear,
        .upSampling = TextureSampling::Linear,
    });

    texture->safeUnbind();

    glFramebufferTexture2D(GL_FRAMEBUFFER,
        getGLAttachment(attachment),
        GL_TEXTURE_2D,
        texture->getTextureId(),
        0);

    safeUnbind();
}

unsigned int Framebuffer::getId() const
{
    return fboId;
}

void Framebuffer::clear()
{
    safeBind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    safeUnbind();
}

void Framebuffer::use(std::function<void()> fnc)
{
    clear();
    bind();
    fnc();
    unbind();
}

GLint Framebuffer::getFormat(FramebufferAttachment attachment)
{
    if (attachment == FramebufferAttachment::Depth) {
        return GL_DEPTH_COMPONENT;
    }

    return GL_RGB;
}

GLint Framebuffer::getGLAttachment(FramebufferAttachment attachment)
{
    if (attachment == FramebufferAttachment::Depth) {
        return GL_DEPTH_ATTACHMENT;
    }

    return GL_COLOR_ATTACHMENT0;
}

void Framebuffer::generate()
{
    glGenFramebuffers(1, &fboId);
}

void Framebuffer::doBind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, fboId);
}

void Framebuffer::doUnbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
