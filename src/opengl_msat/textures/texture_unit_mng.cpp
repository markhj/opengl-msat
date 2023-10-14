#include "opengl_msat/textures/texture_unit_mng.hpp"

TextureUnitManager::TextureUnitManager(SystemInfo *systemInfo) : systemInfo(systemInfo)
{

}

unsigned int TextureUnitManager::getAvailableSlots() const
{
    return systemInfo->maxTextureUnits;
}
