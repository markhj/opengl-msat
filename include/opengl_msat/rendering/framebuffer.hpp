#ifndef OPENGL_MSAT_FRAMEBUFFER_HPP
#define OPENGL_MSAT_FRAMEBUFFER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture2d.hpp"

class Framebuffer {
public:
    Framebuffer(unsigned int  width, unsigned int  height) : texture(Texture2D(width, height))
    {
        glGenFramebuffers(1, &fboId);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.getTextureId(), 0);
    }

protected:
    unsigned int fboId;

    Texture2D texture;

};

#endif
