#ifndef OPENGL_MSAT_MOUSE_HPP
#define OPENGL_MSAT_MOUSE_HPP

#include <functional>
#include <optional>
#include <array>
#include "mouse_mapping.hpp"

/**
 * Mouse
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/controls/mouse/
 */
class Mouse {
public:
    void moved(std::array<float, 2> pos, std::array<float, 2> diff);

    /**
     * @todo Implement for Linux
     * @todo Implement for Mac
     */
    void setPosition(unsigned int x, unsigned int y);

    /**
     * @todo Implement for Linux
     * @todo Implement for Mac
     */
    void hideCursor() const;

    /**
     * @todo Implement for Linux
     * @todo Implement for Mac
     */
    void showCursor() const;

    MouseMapping* mouseMapping = nullptr;

};

#endif
