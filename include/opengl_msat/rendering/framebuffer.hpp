#ifndef OPENGL_MSAT_FRAMEBUFFER_HPP
#define OPENGL_MSAT_FRAMEBUFFER_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture2d.hpp"
#include "opengl_msat/context/context.hpp"

/**
 * Framebuffer attachment
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/framebuffer-enums/
 */
enum class FramebufferAttachment {
    Color,
    Depth,
};

/**
 * Framebuffer
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/fbo/fbo/
 *
 * @todo Implement support for multiple color attachment points
 */
class Framebuffer : public Bindable {
public:
    Framebuffer(unsigned int width, unsigned int height);

    void attach(Texture2D* texture);

    void attach(Texture2D* texture, FramebufferAttachment attachment);

    [[nodiscard]] unsigned int getId() const;

    void clear();

    void use(std::function<void()> fnc);

protected:
    unsigned int fboId, width, height;

    GLint getFormat(FramebufferAttachment attachment);

    GLint getGLAttachment(FramebufferAttachment attachment);

    void generate();

    void doBind() override;

    void doUnbind() override;

};

#endif
