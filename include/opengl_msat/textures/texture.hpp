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

enum TextureFormat {
    Red = GL_RED,
    Green = GL_GREEN,
    Blue = GL_BLUE,
    RGB = GL_RGB,
    RGBA = GL_RGBA,
    DepthComponent = GL_DEPTH_COMPONENT,
    StencilComponent = GL_DEPTH_STENCIL,
    Luminance = GL_LUMINANCE,
    LuminanceAlpha = GL_LUMINANCE_ALPHA,
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

    TextureDownsampling downSampling = TextureDownsampling::Nearest;
    TextureSampling upSampling = TextureSampling::Nearest;

    TextureFormat format = TextureFormat::RGB;

    bool mipmap = false;
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
