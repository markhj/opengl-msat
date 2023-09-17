#include "opengl_msat/tools/system.hpp"

SystemInfo System::getSystemInfo(Window* window)
{
    return {
        .openGLVersion = getVersion(),
        .gpu = gpu(),

        .maxTextureUnits = getValue(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS),
        .maxTextureSize = getValue(GL_MAX_TEXTURE_SIZE),
        .maxTextureSizeCubemap = getValue(GL_MAX_CUBE_MAP_TEXTURE_SIZE),
        .maxTextureSize3D = getValue(GL_MAX_3D_TEXTURE_SIZE),

        .maxUniformLocations = getValue(GL_MAX_UNIFORM_LOCATIONS),

        .framebufferMaxWidth = getValue(GL_MAX_FRAMEBUFFER_WIDTH),
        .framebufferMaxHeight = getValue(GL_MAX_FRAMEBUFFER_HEIGHT),
    };
}

const char* System::getChar(GLint input)
{
    return reinterpret_cast<const char*>(glGetString(input));
}

GPU System::gpu()
{
    return {
        .name = getChar(GL_RENDERER),
        .vendor = getChar(GL_VENDOR),
        .driverVersion = getChar(GL_VERSION)
    };
}

OpenGLVersion System::getVersion()
{
    unsigned int majorVersion, minorVersion;
    const char* versionAsString = getChar(GL_VERSION);
    sscanf(versionAsString, "%d.%d", &majorVersion, &minorVersion);

    return {
        .version = versionAsString,
        .major = majorVersion,
        .minor = minorVersion
    };
}

GLint System::getValue(GLint input)
{
    GLint value;
    glGetIntegerv(input, &value);
    return value;
};