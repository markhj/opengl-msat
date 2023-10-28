#ifndef OPENGL_MSAT_LOADS_IMAGES_HPP
#define OPENGL_MSAT_LOADS_IMAGES_HPP

#include <optional>
#include <string>
#include "opengl_msat/types/image.hpp"
#include "dev_messaging.hpp"

/**
 * Loads images (trait)
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/misc/image/
 */
class LoadsImages :
        public DeveloperMessaging {
protected:
    std::optional<Image> loadImage(std::string filename);

};

#endif