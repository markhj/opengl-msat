#include "opengl_msat/textures/texture_unit_mng.hpp"

TextureUnitManager::TextureUnitManager(SystemInfo *systemInfo) : systemInfo(systemInfo)
{

}

unsigned int TextureUnitManager::getAvailableSlots() const
{
    return systemInfo->maxTextureUnits;
}

void TextureUnitManager::bindTextureTo(unsigned int unit, Texture *texture)
{
    with(unit, [&]() {
        texture->bind();
    });

    texture->unbind();
}
