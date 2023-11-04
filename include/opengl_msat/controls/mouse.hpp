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

    MouseMapping* mouseMapping = nullptr;

};

#endif
