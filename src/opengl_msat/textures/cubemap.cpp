#include "opengl_msat/textures/cubemap.hpp"

CubeMap::CubeMap(const std::vector<std::string> &files)
    : Texture(TextureType::CubeMap, files, {})
{
    validateCreation(files);
}

CubeMap::CubeMap(const std::vector<std::string> &files, TextureOptions options)
    : Texture(TextureType::CubeMap, files, options)
{
    validateCreation(files);
}

void CubeMap::validateCreation(const std::vector<std::string> &files)
{
    if (files.size() != 6) {
        warn("You should provide exactly 6 filenames to a cubemap.");
    }
}
