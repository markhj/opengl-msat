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

    build(pixelHeight);

    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

void Font::build(unsigned int pixelHeight)
{
    int totalWidth = 0;
    int numGlyphs = 128;

    GLint unpackAlignment;

    // Store the current GL_UNPACK_ALIGNMENT so we can restore this value
    // at the end of the function
    glGetIntegerv(GL_UNPACK_ALIGNMENT, &unpackAlignment);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Determine the width of the texture
    for (unsigned char c = 0; c < numGlyphs; c++) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            warn("Failed to load font glyph");
            continue;
        }

        totalWidth += face->glyph->bitmap.width;
    }

    // Create the texture (with the calculated total width of the glyphs)
    fontTexture = Texture2D(totalWidth, pixelHeight, {
        .wrapping = TexturePattern::ClampToEdge,
        .downSampling = TextureDownsampling::Linear,
        .upSampling = TextureSampling::Linear,
        .format = TextureFormat::Red,
    });

    fontTexture.bind();

    // Insert each glyph on the texture
    for (unsigned char c = 0; c < numGlyphs; c++) {
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
    }
    fontTexture.unbind();

    glPixelStorei(GL_UNPACK_ALIGNMENT, unpackAlignment);
}

Texture2D *Font::texture()
{
    return &fontTexture;
}
