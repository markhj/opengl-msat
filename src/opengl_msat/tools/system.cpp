#include "opengl_msat/tools/system.hpp"
#include <regex>

std::map<GLint, int> System::fakedValues = {};

SystemInfo System::getSystemInfo(Window* window)
{
    return {
        .openGLVersion = getVersion(),
        .gpu = gpu(),

        .maxTextureUnits = getValue(GL_MAX_TEXTURE_IMAGE_UNITS),

        .maxTextureSize = getValue(GL_MAX_TEXTURE_SIZE),
        .maxTextureSizeCubemap = getValue(GL_MAX_CUBE_MAP_TEXTURE_SIZE),
        .maxTextureSize3D = getValue(GL_MAX_3D_TEXTURE_SIZE),

        .maxUniformLocations = getValue(GL_MAX_UNIFORM_LOCATIONS),

        .maxFramebuffers = getValue(GL_MAX_DRAW_BUFFERS),
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
    unsigned int majorVersion = 0, minorVersion = 0;
    std::string versionAsString = getChar(GL_VERSION);

    std::regex pattern("([0-9]+)\\.([0-9]+)");
    std::smatch match;
    if (std::regex_search(versionAsString, match, pattern)) {
        std::string majorStr = match[1].str();
        std::string minorStr = match[2].str();
        majorVersion = std::stoi(majorStr);
        minorVersion = std::stoi(minorStr);
    }

    return {
        .version = versionAsString,
        .major = majorVersion,
        .minor = minorVersion
    };
}

GLint System::getValue(GLint input)
{
    auto find = fakedValues.find(input);
    if (find != fakedValues.end()) {
        return find->second;
    }

    GLint value;
    glGetIntegerv(input, &value);
    return value;
}

void System::fake(GLint variable, int value)
{
    fakedValues.insert(std::make_pair(variable, value));
};