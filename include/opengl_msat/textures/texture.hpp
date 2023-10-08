#ifndef OPENGL_MSAT_TEXTURE_HPP
#define OPENGL_MSAT_TEXTURE_HPP

#include <string>
#include "opengl_msat/types/image.hpp"
#include "opengl_msat/traits/loads_images.hpp"

enum TextureType {
    Texture2D,
    Texture3D,
    Cubemap,
};

class Texture :
        LoadsImages {
public:
    explicit Texture(TextureType type, std::string filename);

protected:
    Image image;

    TextureType type;

};

#endif
