#include <utility>

#include "opengl_msat/textures/texture.hpp"

Texture::Texture(TextureType type, std::string filename) : type(type)
{
    std::optional<Image> img = loadImage(std::move(filename));
}
