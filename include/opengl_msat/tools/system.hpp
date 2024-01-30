#ifndef OPENGL_MSAT_SYSINFO_HPP
#define OPENGL_MSAT_SYSINFO_HPP

#include <map>
#include "opengl_msat/common.h"
#include "opengl_msat/window/window.hpp"
#include "systeminfo.hpp"

/**
 * System
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/tools/sysinfo/
 */
class System {
public:
    static SystemInfo getSystemInfo(Window* window);

    static void fake(GLint variable, int value);

private:
    static GLint getValue(GLint input);

    static OpenGLVersion getVersion();

    static GPU gpu();

    static const char* getChar(GLint input);

    static std::map<GLint, int> fakedValues;

};

#endif
