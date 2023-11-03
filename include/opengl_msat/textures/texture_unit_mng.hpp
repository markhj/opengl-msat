#ifndef OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP
#define OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP

#include "opengl_msat/tools/systeminfo.hpp"
#include "opengl_msat/traits/dev_messaging.hpp"
#include "opengl_msat/traits/binding_mng.hpp"
#include "opengl_msat/common.h"
#include "texture.hpp"
#include "opengl_msat/shader/shader.hpp"

/**
 * Texture unit manager
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/textures/tum/
 */
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
    void attachShader(ShaderProgram* shader);

    void detachShader(ShaderProgram* shader);

    void bindTextureTo(unsigned int unit, Texture* texture);

    [[nodiscard]] unsigned int getBoundTo() const override;

    /**
     * Retrieve the texture currently bound to the specified unit
     * Returns std::nullopt if nothing is bound on the slot
     *
     * @param slot
     * @return std::optional<Texture*>
     */
    std::optional<Texture*> get(unsigned int slot);

    /**
     * Returns either the slot number where the texture is bound, or
     * a std::nullopt if the texture isn't bound
     *
     * @param texture
     * @return std::optional<unsigned int>
     */
    std::optional<unsigned int> getTextureBinding(Texture* texture);

    void lock(unsigned int slot);

    void unlock(unsigned int slot);

    bool isLocked(unsigned int slot);

    bool warnWhenBindingToLockedUnit = true;

protected:
    void doBindTo(unsigned int to) override;

private:
    SystemInfo* systemInfo;

    std::map<unsigned int, Texture*> bindings;

    std::map<unsigned int, ShaderProgram*> shaders;

    std::vector<unsigned int> lockedSlots;

};

#endif
