#include "opengl_msat/controls/mouse.hpp"

void Mouse::onMove(std::function<void(std::array<float, 2>, std::array<float, 2>)> func)
{
    onMoveFunc = func;
}

void Mouse::moved(std::array<float, 2> pos, std::array<float, 2> diff)
{
    if (onMoveFunc.has_value()) {
        onMoveFunc.value()(pos, diff);
    }
}
