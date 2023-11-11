#include "opengl_msat/text/font.hpp"
#include <iostream>

Font::Font(const char *filename)
{
    construct(filename, 60);
}

Font::Font(const char *filename, unsigned int pixelHeight)
{
    construct(filename, pixelHeight);
}

void Font::construct(const char *filename, unsigned int pixelHeight)
{
    if (FT_Init_FreeType(&ft)) {
        critical("Failed to initialize Freetype library");
        return;
    }

    if (FT_New_Face(ft, filename, 0, &face)) {
        warn(static_cast<std::string>("Failed to load font: ") + filename);
        return;
    }

    FT_Set_Pixel_Sizes(face, 0, pixelHeight);

    build();

    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

void Font::build()
{
    fontTexture = Texture2D(100, 100);
}

Texture2D *Font::texture()
{
    return &fontTexture;
}
