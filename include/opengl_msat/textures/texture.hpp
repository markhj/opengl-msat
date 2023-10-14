#ifndef OPENGL_MSAT_TEXTURE_HPP
#define OPENGL_MSAT_TEXTURE_HPP

#include <string>
#include "opengl_msat/common.h"
#include "opengl_msat/types/image.hpp"
#include "opengl_msat/traits/loads_images.hpp"
#include "opengl_msat/traits/bindable.hpp"

enum TextureType {
    Texture2D = GL_TEXTURE_2D,
};

enum TexturePattern {
    Repeat = GL_REPEAT,
    RepeatMirrored = GL_MIRRORED_REPEAT,
    ClampToEdge = GL_CLAMP_TO_EDGE,
    ClampToBorder = GL_CLAMP_TO_BORDER
};

enum class TextureSampling {
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR,
};

enum class TextureDownsampling {
    MipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
    MipmapLinear = GL_NEAREST_MIPMAP_NEAREST,
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR,
};

struct TextureOptions {
    TexturePattern wrapping = TexturePattern::Repeat;
    TextureDownsampling downSampling = TextureDownsampling::MipmapNearest;
    TextureSampling upSampling = TextureSampling::Nearest;
};

class Texture :
        LoadsImages,
        public Bindable {
public:
    Texture(TextureType type, std::string filename);

    Texture(TextureType type, std::string filename, TextureOptions options);

    [[nodiscard]] unsigned int getTextureId() const;

    [[nodiscard]] bool isLoaded() const;

    void doBind() override;

    void doUnbind() override;

    std::optional<unsigned int> boundToUnit;

    void applyOptions(TextureOptions options);

protected:
    bool loaded = false;

    unsigned int textureId;

    Image image;

    TextureType type;

};

#endif
