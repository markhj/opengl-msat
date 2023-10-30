#ifndef OPENGL_MSAT_TEXTURE_HPP
#define OPENGL_MSAT_TEXTURE_HPP

#include <string>
#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/types/image.hpp"
#include "opengl_msat/traits/loads_images.hpp"
#include "opengl_msat/traits/bindable.hpp"

/**
 * Texture load status
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/texture-enums/
 */
enum class TextureLoadStatus {
    None,
    Partial,
    Success,
};

/**
 * Texture type
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/texture-enums/
 */
enum class TextureType {
    Texture2D,
    CubeMap,
};

/**
 * Texture pattern
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/texture-enums/
 */
enum TexturePattern {
    Repeat = GL_REPEAT,
    RepeatMirrored = GL_MIRRORED_REPEAT,
    ClampToEdge = GL_CLAMP_TO_EDGE,
    ClampToBorder = GL_CLAMP_TO_BORDER
};

/**
 * Texture format
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/texture-enums/
 */
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

/**
 * Texture sampling (general, up)
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/texture-enums/
 */
enum class TextureSampling {
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR,
};

/**
 * Texture down sampling
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/texture-enums/
 */
enum class TextureDownsampling {
    MipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
    MipmapLinear = GL_NEAREST_MIPMAP_NEAREST,
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR,
};

/**
 * Texture options
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/textures/texture-options/
 */
struct TextureOptions {
    TexturePattern wrapping = TexturePattern::Repeat;

    TextureDownsampling downSampling = TextureDownsampling::Nearest;
    TextureSampling upSampling = TextureSampling::Nearest;

    TextureFormat format = TextureFormat::RGB;

    bool mipmap = false;
};

/**
 * Texture
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/textures/textures/
 */
class Texture :
        LoadsImages,
        public Bindable {
public:
    Texture(TextureType type, unsigned int width, unsigned int height);

    Texture(TextureType type, unsigned int width, unsigned int height, TextureOptions options);

    Texture(TextureType type, std::string filename);

    Texture(TextureType type, std::string filename, TextureOptions options);

    Texture(TextureType type, std::vector<std::string> files, TextureOptions options);

    [[nodiscard]] unsigned int getTextureId() const;

    [[nodiscard]] TextureLoadStatus isLoaded() const;

    void doBind() override;

    void doUnbind() override;

    std::optional<unsigned int> boundToUnit;

    void applyOptions(TextureOptions options);

protected:
    TextureLoadStatus loaded = TextureLoadStatus::None;

    unsigned int textureId;

    Image image;

    TextureType type;

    GLint getGlType(TextureType type);

    GLint getGlTypeIter(TextureType type, int i);

    void generateId();

    void generate(GLint txType,
                  unsigned int width,
                  unsigned int height,
                  unsigned char* data,
                  TextureOptions options);

private:
    void load(const std::vector<std::string>& filenames, TextureOptions options);

};

#endif
