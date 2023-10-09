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

        bind();
        glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(type, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.data);
        glGenerateMipmap(type);
        unbind();
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
