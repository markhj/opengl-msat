#ifndef OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP
#define OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP

#include "opengl_msat/shared/systeminfo.hpp"
#include "opengl_msat/traits/dev_messaging.hpp"
#include "opengl_msat/bindable/bindable.hpp"
#include "opengl_msat/common.h"
#include "texture.hpp"

class TextureUnitManager :
        DeveloperMessaging,
        Bindable {
public:
    explicit TextureUnitManager(SystemInfo* systemInfo);

    [[nodiscard]] unsigned int getUnitsAvailable() const;

    void bindTextureTo(unsigned int unit, Texture* texture);

private:
    SystemInfo* systemInfo;

};

#endif
