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

class Texture :
        LoadsImages,
        public Bindable {
public:
    explicit Texture(TextureType type, std::string filename);

    [[nodiscard]] unsigned int getTextureId() const;

    [[nodiscard]] bool isLoaded() const;

    void doBind() override;

    void doUnbind() override;

    std::optional<unsigned int> boundToUnit;

protected:
    bool loaded = false;

    unsigned int textureId;

    Image image;

    TextureType type;

};

#endif
