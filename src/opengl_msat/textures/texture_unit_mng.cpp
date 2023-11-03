#include "opengl_msat/textures/texture_unit_mng.hpp"

TextureUnitManager::TextureUnitManager(SystemInfo *systemInfo) : systemInfo(systemInfo)
{

}

unsigned int TextureUnitManager::getAvailableSlots() const
{
    return systemInfo->maxTextureUnits;
}

void TextureUnitManager::attachShader(ShaderProgram *shader)
{
    shaders.insert(std::make_pair(shader->getProgramId(), shader));

    // Create entries and assign values on all available texture units
    for (int i = 0; i < systemInfo->maxTextureUnits; i++) {
        shader->uniform("textures", i, i);
    }
}

void TextureUnitManager::detachShader(ShaderProgram *shader)
{
    shaders.erase(shader->getProgramId());
}

void TextureUnitManager::bindTextureTo(unsigned int unit, Texture *texture)
{
    if (isLocked((unit))) {
        if (warnWhenBindingToLockedUnit) {
            warn("Attempting to bind to unit " + std::to_string(unit) + " while it is locked.");
        }
        return;
    }

    // Indicate on the texture currently bound to this slot (if any)
    // that it's no longer bound
    std::optional<Texture*> current = get(unit);
    if (current.has_value()) {
        current.value()->boundToUnit = std::nullopt;
    }

    with(unit, [&]() {
        texture->bind();
    });

    texture->boundToUnit = unit;

    bindings[unit] = texture;
}

unsigned int TextureUnitManager::getBoundTo() const
{
    GLuint activeTextureUnit;
    glGetIntegerv(GL_ACTIVE_TEXTURE, (GLint*)&activeTextureUnit);
    return activeTextureUnit - GL_TEXTURE0;
}

std::optional<Texture *> TextureUnitManager::get(unsigned int slot)
{
    auto find = bindings.find(slot);
    if (find != bindings.end()) {
        return find->second;
    }
    return std::nullopt;
}

std::optional<unsigned int> TextureUnitManager::getTextureBinding(Texture *texture)
{
    for (const auto& [unit, boundTexture] : bindings) {
        if (boundTexture == texture) {
            return unit;
        }
    }

    return std::nullopt;
}

void TextureUnitManager::doBindTo(unsigned int to)
{
    glActiveTexture(GL_TEXTURE0 + to);
}

void TextureUnitManager::lock(unsigned int slot)
{
    if (!isLocked(slot)) {
        lockedSlots.push_back(slot);
    }
}

void TextureUnitManager::unlock(unsigned int slot)
{
    lockedSlots.erase(std::remove(lockedSlots.begin(),
                                  lockedSlots.end(),
                                  slot), lockedSlots.end());
}

bool TextureUnitManager::isLocked(unsigned int slot)
{
    return std::find(lockedSlots.begin(),
                     lockedSlots.end(),
                     slot) != lockedSlots.end();
}
