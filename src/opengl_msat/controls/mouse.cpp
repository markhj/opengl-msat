#include "opengl_msat/controls/mouse.hpp"

#if _WIN32
#include <windows.h>
#include <iostream>

#endif

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

void Mouse::setPosition(unsigned int x, unsigned int y)
{
#if _WIN32
    SetCursorPos(x, y);
#else
    std::cout << "Mouse::setPosition not implemented for this platform." << std::endl;
#endif
}
