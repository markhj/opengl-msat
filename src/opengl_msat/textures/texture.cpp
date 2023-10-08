#include <utility>
#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture.hpp"

Texture::Texture(TextureType type, std::string filename) : type(type)
{
    std::optional<Image> img = loadImage(std::move(filename));

    if (img.has_value()) {
        loaded = true;
        image = img.value();

        glGenTextures(1, &textureId);
    }
}

unsigned int Texture::getTextureId() const
{
    return textureId;
}

bool Texture::isLoaded() const
{
    return loaded;
}

void Texture::doBind()
{
    glBindTexture(GL_TEXTURE_2D, getTextureId());
}

void Texture::doUnbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
