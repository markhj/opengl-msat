#ifndef OPENGL_MSAT_FRAMEBUFFER_MNG_HPP
#define OPENGL_MSAT_FRAMEBUFFER_MNG_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/traits/binding_mng.hpp"
#include "opengl_msat/tools/systeminfo.hpp"
#include "framebuffer.hpp"

class FramebufferManager : public ManagesMultipleBindings {
public:
    explicit FramebufferManager(SystemInfo* systemInfo) : systemInfo(systemInfo)
    {

    }

    [[nodiscard]] unsigned int getAvailableSlots() const
    {
        return systemInfo->maxFramebuffers;
    }

    [[nodiscard]] unsigned int getBoundTo() const
    {
        GLuint boundFramebuffer;
        glGetIntegerv(GL_FRAMEBUFFER_BINDING, reinterpret_cast<GLint*>(&boundFramebuffer));
        return boundFramebuffer;
    }

protected:
    void doBindTo(unsigned int slot) override
    {
        glBindFramebuffer(GL_FRAMEBUFFER, slot);
    }

    SystemInfo* systemInfo;

};

#endif
