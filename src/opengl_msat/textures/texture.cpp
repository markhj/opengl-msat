#include <utility>
#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture.hpp"

Texture::Texture(TextureType type, std::string filename) : Texture(type, filename, {})
{

}

Texture::Texture(TextureType type, std::string filename, TextureOptions options) : type(type)
{
    std::optional<Image> img = loadImage(std::move(filename));

    if (img.has_value()) {
        loaded = true;
        image = img.value();

        glGenTextures(1, &textureId);

        applyOptions(options);
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

void Texture::applyOptions(TextureOptions options)
{
    bind();

    if (!options.mipmap && (
            options.downSampling == TextureDownsampling::MipmapLinear
            || options.downSampling == TextureDownsampling::MipmapNearest)) {
        warn("You are using mipmap related options without generating a mipmap. This may cause the texture to not render.");
    }

    glTexParameteri(type, GL_TEXTURE_WRAP_S, options.wrapping);
    glTexParameteri(type, GL_TEXTURE_WRAP_T, options.wrapping);
    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(options.downSampling));
    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(options.upSampling));

    glTexImage2D(type, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.data);

    if (options.mipmap) {
        glGenerateMipmap(type);
    }

    unbind();
}
