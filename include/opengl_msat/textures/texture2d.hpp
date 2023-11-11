#ifndef OPENGL_MSAT_TEXTURE2D_HPP
#define OPENGL_MSAT_TEXTURE2D_HPP

#include <utility>
#include "texture.hpp"

/**
 * Simplified version of Texture which focuses on 2D textures
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/textures/textures/
 */
class Texture2D : public Texture {
public:
    explicit Texture2D(std::string filename);

    Texture2D(std::string filename, TextureOptions options);

    Texture2D(unsigned int width, unsigned int height, TextureOptions options);

    Texture2D(unsigned int width, unsigned int height);

    void saveTo(const char* filename);

};

#endif
