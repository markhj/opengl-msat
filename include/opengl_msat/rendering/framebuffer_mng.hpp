#ifndef OPENGL_MSAT_FRAMEBUFFER_MNG_HPP
#define OPENGL_MSAT_FRAMEBUFFER_MNG_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/traits/binding_mng.hpp"
#include "opengl_msat/tools/systeminfo.hpp"
#include "framebuffer.hpp"

/**
 * Framebuffer manager
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/fbo/fbo-mng/
 */
class FramebufferManager : public ManagesMultipleBindings {
public:
    explicit FramebufferManager(SystemInfo* systemInfo);

    [[nodiscard]] unsigned int getAvailableSlots() const override;

    [[nodiscard]] unsigned int getBoundTo() const override;

protected:
    void doBindTo(unsigned int slot) override;

    SystemInfo* systemInfo;

};

#endif
