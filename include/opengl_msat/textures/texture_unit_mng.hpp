#ifndef OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP
#define OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP

#include "opengl_msat/shared/systeminfo.hpp"

class TextureUnitManager {
public:
    explicit TextureUnitManager(SystemInfo* systemInfo);

    [[nodiscard]] unsigned int getUnitsAvailable() const;

private:
    SystemInfo* systemInfo;

};

#endif
