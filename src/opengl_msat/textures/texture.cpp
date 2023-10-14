#include <utility>
#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture.hpp"

Texture::Texture(TextureType type, std::string filename) : type(type)
{
    load({std::move(filename)}, {});
}

Texture::Texture(TextureType type, std::string filename, TextureOptions options) : type(type)
{
    load({std::move(filename)}, options);
}

void Texture::load(const std::vector<std::string>& filenames, TextureOptions options)
{
    glGenTextures(1, &textureId);

    std::vector<std::optional<Image>> images;
    for (std::string filename : filenames) {
        std::optional<Image> img = loadImage(std::move(filename));
        if (img.has_value()) {
            image = img.value();

            bind();
            glTexImage2D(type,
                         0,
                         options.format,
                         image.width,
                         image.height,
                         0,
                         options.format,
                         GL_UNSIGNED_BYTE,
                         image.data);
            unbind();

            applyOptions(options);
        }
    }

    loaded = true;
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
    glBindTexture(type, getTextureId());
}

void Texture::doUnbind()
{
    glBindTexture(type, 0);
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

    if (options.mipmap) {
        glGenerateMipmap(type);
    }

    unbind();
}
