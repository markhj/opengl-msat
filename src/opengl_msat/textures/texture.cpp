#include <utility>
#include "opengl_msat/common.h"
#include "opengl_msat/textures/texture.hpp"

Texture::Texture(TextureType type, unsigned int width, unsigned int height) : type(type)
{
    generateId();
    generate(getGlType(type), width, height, nullptr, {});
}

Texture::Texture(TextureType type, unsigned int width, unsigned int height, TextureOptions options) : type(type)
{
    generateId();
    generate(getGlType(type), width, height, nullptr, options);
}

Texture::Texture(TextureType type, std::string filename) : type(type)
{
    load({std::move(filename)}, {});
}

Texture::Texture(TextureType type, std::string filename, TextureOptions options) : type(type)
{
    load({std::move(filename)}, options);
}

Texture::Texture(TextureType type, std::vector<std::string> files, TextureOptions options) : type(type)
{
    load(files, options);
}

void Texture::load(const std::vector<std::string>& filenames, TextureOptions options)
{
    generateId();

    int noLoaded = 0, i = 0;

    std::vector<std::optional<Image>> images;
    for (std::string filename : filenames) {
        std::optional<Image> img = loadImage(std::move(filename));

        if (!img.has_value()) {
            i++;
            continue;
        }

        noLoaded++;

        image = img.value();

        generate(getGlTypeIter(type, i), image.width, image.height, image.data, options);

        applyOptions(options);

        i++;
    }

    // Keep in mind that the Image trait will throw errors when an image
    // couldn't get loaded. This status can be retrieved at later points.
    if (noLoaded == 0) {
        loaded = TextureLoadStatus::None;
    } else if (noLoaded < filenames.size()) {
        loaded = TextureLoadStatus::Partial;
    } else {
        loaded = TextureLoadStatus::Success;
    }
}

void Texture::generate(GLint txType,
                       unsigned int width,
                       unsigned int height,
                       unsigned char *data,
                       TextureOptions options)
{
    bind();
    glTexImage2D(txType,
                 0,
                 options.format,
                 width,
                 height,
                 0,
                 options.format,
                 GL_UNSIGNED_BYTE,
                 data);
    unbind();
}

unsigned int Texture::getTextureId() const
{
    return textureId;
}

TextureLoadStatus Texture::isLoaded() const
{
    return loaded;
}

void Texture::doBind()
{
    glBindTexture(getGlType(type), getTextureId());
}

void Texture::doUnbind()
{
    glBindTexture(getGlType(type), 0);
}

void Texture::applyOptions(TextureOptions options)
{
    bind();

    if (!options.mipmap && (
            options.downSampling == TextureDownsampling::MipmapLinear
            || options.downSampling == TextureDownsampling::MipmapNearest)) {
        warn("You are using mipmap related options without generating a mipmap. This may cause the texture to not render.");
    }

    GLint tp = getGlType(type);

    glTexParameteri(tp, GL_TEXTURE_WRAP_S, options.wrapping);
    glTexParameteri(tp, GL_TEXTURE_WRAP_T, options.wrapping);
    glTexParameteri(tp, GL_TEXTURE_WRAP_R, options.wrapping);
    glTexParameteri(tp, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(options.downSampling));
    glTexParameteri(tp, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(options.upSampling));

    if (options.mipmap) {
        glGenerateMipmap(tp);
    }

    unbind();
}

GLint Texture::getGlType(TextureType type)
{
    switch (type) {
        case TextureType::Texture2D:
            return GL_TEXTURE_2D;
        case TextureType::CubeMap:
            return GL_TEXTURE_CUBE_MAP;
    }
}

GLint Texture::getGlTypeIter(TextureType type, int i)
{
    switch (type) {
        case TextureType::Texture2D:
            return GL_TEXTURE_2D;
        case TextureType::CubeMap:
            return GL_TEXTURE_CUBE_MAP_POSITIVE_X + i;
    }
}

void Texture::generateId()
{
    glGenTextures(1, &textureId);
}
