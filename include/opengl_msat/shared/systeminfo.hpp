#ifndef OPENGL_MSAT_SYSTEMINFO_HPP
#define OPENGL_MSAT_SYSTEMINFO_HPP

struct OpenGLVersion {
    const char* version;
    const unsigned int major, minor;
};

struct GPU {
    const char *name, *vendor, *driverVersion;
};

struct CPU {
    unsigned int cores;
};

struct SystemInfo {
    const OpenGLVersion openGLVersion;
    const GPU gpu;
    const CPU cpu;
    const int maxTextureUnits;
};

#endif
