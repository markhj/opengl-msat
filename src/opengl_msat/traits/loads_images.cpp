#include "opengl_msat/traits/loads_images.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::optional<Image> LoadsImages::loadImage(std::string filename)
{
    int width, height, nrChannels;

    unsigned char *data = stbi_load(filename.c_str(),
                                    &width,
                                    &height,
                                    &nrChannels,
                                    0);

    if (!data) {
        warn("Failed to load image: " + filename);
        return std::nullopt;
    }

    std::cout << "LOADED!";

    stbi_image_free(data);

    return std::nullopt;
}
