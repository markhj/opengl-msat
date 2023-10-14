#ifndef OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP
#define OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP

#include "opengl_msat/tools/systeminfo.hpp"
#include "opengl_msat/traits/dev_messaging.hpp"
#include "opengl_msat/traits/binding_mng.hpp"
#include "opengl_msat/common.h"
#include "texture.hpp"
#include "opengl_msat/shader/shader.hpp"

class TextureUnitManager :
        public ManagesMultipleBindings {
public:
    explicit TextureUnitManager(SystemInfo* systemInfo);

    [[nodiscard]] unsigned int getAvailableSlots() const override;

    /**
     * Shaders which are attached automatically have their uniform
     * texture mapping arrays updated
     *
     * @param shader
     */
    void attachShader(ShaderProgram* shader)
    {
        shaders.insert(std::make_pair(shader->getProgramId(), shader));

        // Create entries and assign values on all available texture units
        for (int i = 0; i < systemInfo->maxTextureUnits; i++) {
            shader->uniform("textures", i, i);
        }
    }

    void detachShader(ShaderProgram* shader)
    {
        shaders.erase(shader->getProgramId());
    }

    void bindTextureTo(unsigned int unit, Texture* texture)
    {
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
        bindings.insert(std::make_pair(unit, texture));
    }

    [[nodiscard]] unsigned int getBoundTo() const override
    {
        GLuint activeTextureUnit;
        glGetIntegerv(GL_ACTIVE_TEXTURE, (GLint*)&activeTextureUnit);
        return activeTextureUnit - GL_TEXTURE0;
    }

    /**
     * Retrieve the texture currently bound to the specified unit
     * Returns std::nullopt if nothing is bound on the slot
     *
     * @param slot
     * @return std::optional<Texture*>
     */
    std::optional<Texture*> get(unsigned int slot)
    {
        auto find = bindings.find(slot);
        if (find != bindings.end()) {
            return find->second;
        }
        return std::nullopt;
    }

    /**
     * Returns either the slot number where the texture is bound, or
     * a std::nullopt if the texture isn't bound
     *
     * @param texture
     * @return std::optional<unsigned int>
     */
    std::optional<unsigned int> getTextureBinding(Texture* texture)
    {
        for (const auto& [unit, boundTexture] : bindings) {
            if (boundTexture == texture) {
                return unit;
            }
        }

        return std::nullopt;
    }

protected:
    void doBindTo(unsigned int to) override
    {
        glActiveTexture(GL_TEXTURE0 + to);
    }

private:
    SystemInfo* systemInfo;

    std::map<unsigned int, Texture*> bindings;

    std::map<unsigned int, ShaderProgram*> shaders;

};

#endif
