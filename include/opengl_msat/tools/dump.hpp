#ifndef OPENGL_MSAT_DUMP_HPP
#define OPENGL_MSAT_DUMP_HPP

#include <string>
#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/geometry/vectors.hpp"
#include "systeminfo.hpp"

class Dump {
public:
    static void dump(Mat4 value);

    static void dump(Vec3 value);

    static void dump(Vec2 value);

    static void dump(SystemInfo systemInfo);

private:
    static std::string dumpTitle(std::string title);

    static std::string cell(std::string title, std::string value);
};

#endif
