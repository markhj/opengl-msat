#ifndef OPENGL_MSAT_FRAMEBUFFER_HPP
#define OPENGL_MSAT_FRAMEBUFFER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture2d.hpp"
#include "opengl_msat/context/context.hpp"

/**
 * Framebuffer
 *
 * @todo Implement support for multiple color attachment points
 */
class Framebuffer : public Bindable {
public:
    Framebuffer()
    {
        generate();
    }

    Framebuffer(Texture2D* texture)
    {
        generate();
        attach(texture);
    }

    void attach(Texture2D* texture)
    {
        safeBind();
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->getTextureId(), 0);
        safeUnbind();
    }

    unsigned int getId()
    {
        return fboId;
    }

protected:
    unsigned int fboId;

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
