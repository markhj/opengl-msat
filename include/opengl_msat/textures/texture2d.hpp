#ifndef OPENGL_MSAT_TEXTURE2D_HPP
#define OPENGL_MSAT_TEXTURE2D_HPP

#include <utility>

#include "texture.hpp"

/**
 * Simplified version of Texture which focuses on 2D textures
 */
class Texture2D : public Texture {
public:
    explicit Texture2D(std::string filename)
        : Texture(TextureType::Texture2D, std::move(filename))
    {}

    Texture2D(std::string filename, TextureOptions options)
        : Texture(TextureType::Texture2D, std::move(filename), options)
    {}

};

#endif
