#include "opengl_msat/textures/texture_unit_mng.hpp"

TextureUnitManager::TextureUnitManager(SystemInfo *systemInfo) : systemInfo(systemInfo)
{

}

unsigned int TextureUnitManager::getUnitsAvailable() const
{
    return systemInfo->maxTextureUnits;
}
