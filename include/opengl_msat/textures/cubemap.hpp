#ifndef OPENGL_MSAT_CUBEMAP_HPP
#define OPENGL_MSAT_CUBEMAP_HPP

#include "texture.hpp"

class CubeMap : public Texture {
public:
    explicit CubeMap(const std::vector<std::string>& files)
        : Texture(TextureType::CubeMap, files, {})
    {
        validateCreation(files);
    }

    CubeMap(const std::vector<std::string>& files, TextureOptions options)
        : Texture(TextureType::CubeMap, files, options)
    {
        validateCreation(files);
    }

private:
    void validateCreation(const std::vector<std::string>& files)
    {
        if (files.size() != 6) {
            warn("You should provide exactly 6 filenames to a cubemap.");
        }
    }

};

#endif
