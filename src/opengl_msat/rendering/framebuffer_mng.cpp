#include "opengl_msat/rendering/framebuffer_mng.hpp"

FramebufferManager::FramebufferManager(SystemInfo *systemInfo) : systemInfo(systemInfo)
{

}

unsigned int FramebufferManager::getAvailableSlots() const
{
    return systemInfo->maxFramebuffers;
}

unsigned int FramebufferManager::getBoundTo() const
{
    GLuint boundFramebuffer;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, reinterpret_cast<GLint*>(&boundFramebuffer));
    return boundFramebuffer;
}

void FramebufferManager::doBindTo(unsigned int slot)
{
    glBindFramebuffer(GL_FRAMEBUFFER, slot);
}
