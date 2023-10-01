/**
 * Public header
 *
 * The collection of all essential headers gathered in a single file
 * for easy use by consumers of the library
 */

#ifndef OPENGL_MSAT_PUBLIC_HPP
#define OPENGL_MSAT_PUBLIC_HPP

#include "common.h"

// Essentials and misc.
#include "window/window.hpp"
#include "camera/camera.hpp"
#include "context/context.hpp"
#include "timer/timer.hpp"

// Types
#include "types/color.hpp"
#include "shared/keyboard_types.hpp"
#include "shared/lights.hpp"
#include "shared/projections.hpp"
#include "shared/render_types.hpp"
#include "shared/scenes.hpp"
#include "shared/shader_types.hpp"
#include "shared/systeminfo.hpp"
#include "shared/vertex_types.hpp"

// Shader
#include "shader/shader.hpp"
#include "shader/vertex_sbldr.hpp"
#include "shader/fragment_sbldr.hpp"

// Renderer
#include "renderer/renderer.hpp"
#include "renderer/renderstate.hpp"

// Debugging
#include "tools/dump.hpp"
#include "tools/system.hpp"
#include "tools/grid.hpp"

// Vertex, VAO, VBO
#include "vertex/vao.hpp"
#include "vertex/vbo.hpp"
#include "vertex/vbo_scene.hpp"

// Controls
#include "controls/keyboard.hpp"
#include "controls/keyboard_mapping.hpp"

// Geometry
#include "geometry/cube.hpp"
#include "geometry/vectors.hpp"
#include "geometry/matrices.hpp"
#include "geometry/object2d.hpp"
#include "geometry/object3d.hpp"
#include "geometry/rectangle.hpp"
#include "geometry/cube.hpp"

#endif
