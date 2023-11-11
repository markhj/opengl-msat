#include "opengl_msat/textures/texture2d.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Texture2D::Texture2D(std::string filename) : Texture(TextureType::Texture2D, std::move(filename))
{

}

Texture2D::Texture2D(std::string filename, TextureOptions options)
    : Texture(TextureType::Texture2D, std::move(filename), options)
{

}

Texture2D::Texture2D(unsigned int width, unsigned int height, TextureOptions options)
    : Texture(TextureType::Texture2D, width, height, options)
{

}

Texture2D::Texture2D(unsigned int width, unsigned int height)
    : Texture(TextureType::Texture2D, width, height, {})
{

}

void Texture2D::saveTo(const char *filename)
{
    safeBind();

    unsigned int channels = 3;

    unsigned char* pixels = new unsigned char[width * height * channels * channels];

    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    for (int i = 0; i < height / 2; ++i) {
        for (int j = 0; j < width * channels; ++j) {
            std::swap(pixels[i * width * channels + j],
                      pixels[(height - 1 - i) * width * channels + j]
                      );
        }
    }

    stbi_write_png(filename, width, height, channels, pixels, width * channels);

    delete[] pixels;

    safeUnbind();
}
