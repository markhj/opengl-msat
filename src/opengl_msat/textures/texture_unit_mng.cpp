#include "opengl_msat/textures/texture_unit_mng.hpp"

TextureUnitManager::TextureUnitManager(SystemInfo *systemInfo) : systemInfo(systemInfo)
{

}

unsigned int TextureUnitManager::getUnitsAvailable() const
{
    return systemInfo->maxTextureUnits;
}

void TextureUnitManager::bindTextureTo(unsigned int unit, Texture *texture)
{
    glActiveTexture(GL_TEXTURE0 + unit - 1);
    texture->bind();
    glActiveTexture(0);
    texture->unbind();
}
