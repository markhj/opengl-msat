#ifndef OPENGL_MSAT_SYSTEMINFO_HPP
#define OPENGL_MSAT_SYSTEMINFO_HPP

struct OpenGLVersion {
    const char* version;
    const unsigned int major, minor;
};

struct GPU {
    const char *name, *vendor, *driverVersion;
};

/**
 * System info
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/tools/sysinfo/
 */
struct SystemInfo {
    const OpenGLVersion openGLVersion;

    const GPU gpu;

    const int maxTextureUnits;
    const int maxTextureSize;
    const int maxTextureSizeCubemap;
    const int maxTextureSize3D;

    const int maxUniformLocations;

    const int maxFramebuffers, framebufferMaxWidth, framebufferMaxHeight;
};

#endif
