#ifndef OPENGL_MSAT_FONT_HPP
#define OPENGL_MSAT_FONT_HPP

#include <freetype/freetype.h>
#include "opengl_msat/traits/dev_messaging.hpp"
#include "opengl_msat/textures/texture2d.hpp"

/**
 * Font
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/text/font/
 */
class Font : DeveloperMessaging {
public:
    explicit Font(const char* filename);

    Font(const char* filename, unsigned int pixelHeight);

    Texture2D* texture();

private:
    FT_Library ft;

    FT_Face face;

    Texture2D fontTexture = Texture2D(0, 0);

    void construct(const char* filename, unsigned int pixelHeight);

    void build(unsigned int pixelHeight);

};

#endif
