#include "opengl_msat/controls/mouse.hpp"

void Mouse::moved(std::array<float, 2> pos, std::array<float, 2> diff)
{
    if (!mouseMapping) {
        return;
    }

    if (mouseMapping->getOnMove().has_value()) {
        mouseMapping->getOnMove().value()(CursorMoved {
            .x = static_cast<unsigned int>(pos[0]),
            .y = static_cast<unsigned int>(pos[1]),
            .diffX = static_cast<int>(diff[0]),
            .diffY = static_cast<int>(diff[1]),
        });
    }
}
