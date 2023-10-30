#ifndef OPENGL_MSAT_MOUSE_HPP
#define OPENGL_MSAT_MOUSE_HPP

#include <functional>
#include <optional>
#include <array>

/**
 * Mouse
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/controls/mouse/
 */
class Mouse {
public:
    void onMove(std::function<void(std::array<float, 2>, std::array<float, 2>)> func);

    void moved(std::array<float, 2> pos, std::array<float, 2> diff);

private:
    std::optional<std::function<void(std::array<float, 2>, std::array<float, 2>)>> onMoveFunc = std::nullopt;

};

#endif
