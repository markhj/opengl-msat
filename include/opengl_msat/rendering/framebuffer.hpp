#ifndef OPENGL_MSAT_FRAMEBUFFER_HPP
#define OPENGL_MSAT_FRAMEBUFFER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture2d.hpp"
#include "opengl_msat/context/context.hpp"

enum class FramebufferAttachment {
    Color,
    Depth,
};

/**
 * Framebuffer
 *
 * @todo Implement support for multiple color attachment points
 */
class Framebuffer : public Bindable {
public:
    Framebuffer(unsigned int width, unsigned int height) : width(width), height(height)
    {
        generate();
    }

    Framebuffer(unsigned int width, unsigned int height, FramebufferAttachment attachment)
        : width(width), height(height), attachment(attachment)
    {
        generate();
    }

    void attach(Texture2D* texture)
    {
        safeBind();

        texture->safeBind();
        glTexImage2D(GL_TEXTURE_2D, 0, getFormat(), width, height, 0, getFormat(), GL_UNSIGNED_BYTE, nullptr);

        texture->applyOptions({
            .downSampling = TextureDownsampling::Linear,
            .upSampling = TextureSampling::Linear,
        });

        texture->safeUnbind();

        glFramebufferTexture2D(GL_FRAMEBUFFER, getGLAttachment(), GL_TEXTURE_2D, texture->getTextureId(), 0);

        safeUnbind();
    }

    unsigned int getId()
    {
        return fboId;
    }

    void clear()
    {
        safeBind();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        safeUnbind();
    }

    void use(std::function<void()> fnc)
    {
        clear();
        bind();
        fnc();
        unbind();
    }

protected:
    unsigned int fboId, width, height;

    FramebufferAttachment attachment = FramebufferAttachment::Color;

    GLint getFormat()
    {
        switch (attachment) {
            case FramebufferAttachment::Color:
                return GL_RGB;
            case FramebufferAttachment::Depth:
                return GL_DEPTH_COMPONENT;
        }
    }

    GLint getGLAttachment()
    {
        switch (attachment) {
            case FramebufferAttachment::Color:
                return GL_COLOR_ATTACHMENT0;
            case FramebufferAttachment::Depth:
                return GL_DEPTH_ATTACHMENT;
        }
    }

    void generate()
    {
        glGenFramebuffers(1, &fboId);
    }

    void doBind() override
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fboId);
    }

    void doUnbind() override
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

};

#endif
