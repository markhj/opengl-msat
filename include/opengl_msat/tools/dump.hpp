#ifndef OPENGL_MSAT_DUMP_HPP
#define OPENGL_MSAT_DUMP_HPP

#include <string>
#include <optional>
#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/types/vertex_types.hpp"
#include "opengl_msat/geometry/matrices.hpp"
#include "opengl_msat/geometry/vectors.hpp"
#include "systeminfo.hpp"

/**
 * Dump
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/tools/dump/
 */
class Dump {
public:
    static void dump(Mat4 value);

    static void dump(std::optional<Mat4> value);

    static void dump(Vec4 value);

    static void dump(std::optional<Vec4> value);

    static void dump(Vec3 value);

    static void dump(std::optional<Vec3> value);

    static void dump(Vec2 value);

    static void dump(std::optional<Vec2> value);

    static void dump(SystemInfo systemInfo);

    static void dump(std::vector<GLfloat> values);

    static void dump(std::vector<GLfloat> values, unsigned int perRow);

    static void dump(std::vector<GLfloat> values, std::vector<VertexAttribute> attributes);

private:
    static std::string dumpTitle(std::string title);

    static std::string cell(std::string title, std::string value);

    static void printNoValue(std::string type);

};

#endif
