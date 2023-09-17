#ifndef OPENGL_MSAT_SYSINFO_HPP
#define OPENGL_MSAT_SYSINFO_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/window/window.hpp"
#include "opengl_msat/shared/systeminfo.hpp"

class System {
public:
    static SystemInfo getSystemInfo(Window* window);
private:
    static GLint getValue(GLint input);

    static OpenGLVersion getVersion();

    static GPU gpu();

    static const char* getChar(GLint input);
};

#endif
