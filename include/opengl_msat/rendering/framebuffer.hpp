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
    Framebuffer(unsigned int width, unsigned int height) : width(width), height(height)
    {
        generate();
    }

    void attach(Texture2D* texture)
    {
        texture->safeBind();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        texture->safeUnbind();

        safeBind();
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->getTextureId(), 0);
        safeUnbind();
    }

    unsigned int getId()
    {
        return fboId;
    }

protected:
    unsigned int fboId, width, height;

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
