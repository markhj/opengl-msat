#ifndef OPENGL_MSAT_CUBEMAP_HPP
#define OPENGL_MSAT_CUBEMAP_HPP

#include "texture.hpp"

/**
 * Cubemap
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/textures/cubemaps/
 */
class CubeMap : public Texture {
public:
    explicit CubeMap(const std::vector<std::string>& files);

    CubeMap(const std::vector<std::string>& files, TextureOptions options);

private:
    void validateCreation(const std::vector<std::string>& files);

};

#endif
