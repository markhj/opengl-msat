#ifndef OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP
#define OPENGL_MSAT_TEXTURE_UNIT_MNG_HPP

#include "opengl_msat/shared/systeminfo.hpp"
#include "opengl_msat/traits/dev_messaging.hpp"
#include "opengl_msat/traits/binding_mng.hpp"
#include "opengl_msat/common.h"
#include "texture.hpp"

class TextureUnitManager :
        DeveloperMessaging,
        public ManagesMultipleBindings<GLuint> {
public:
    explicit TextureUnitManager(SystemInfo* systemInfo);

    [[nodiscard]] unsigned int getAvailableSlots() const override;

    void bindTextureTo(unsigned int unit, Texture* texture);

    [[nodiscard]] unsigned int getBoundTo() const override
    {
        GLuint activeTextureUnit;
        glGetIntegerv(GL_ACTIVE_TEXTURE, (GLint*)&activeTextureUnit);
        return activeTextureUnit - GL_TEXTURE0;
    }

protected:
    void doBindTo(GLuint to) override
    {
        glActiveTexture(GL_TEXTURE0 + to);
    }

private:
    SystemInfo* systemInfo;

};

#endif
