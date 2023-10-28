#ifndef OPENGL_MSAT_IMAGE_HPP
#define OPENGL_MSAT_IMAGE_HPP

/**
 * Image
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/misc/image/
 */
class Image {
public:
    unsigned char* data;
    unsigned int width, height, channels;
};

#endif
