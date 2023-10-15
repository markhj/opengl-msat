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

// Animation
#include "animation/animation.hpp"

// Textures
#include "textures/texture.hpp"
#include "textures/texture2d.hpp"
#include "textures/texture_unit_mng.hpp"
#include "textures/material.hpp"
#include "textures/cubemap.hpp"
#include "textures/skybox.hpp"

// Types
#include "opengl_msat/types/color.hpp"
#include "opengl_msat/controls/keyboard_types.hpp"
#include "opengl_msat/types/lights.hpp"
#include "opengl_msat/types/projections.hpp"
#include "opengl_msat/types/render_types.hpp"
#include "opengl_msat/types/scenes.hpp"
#include "opengl_msat/types/shader_types.hpp"
#include "opengl_msat/tools/systeminfo.hpp"
#include "opengl_msat/types/vertex_types.hpp"

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
#include "tools/helper.hpp"
#include "traits/dev_messaging.hpp"

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

// UI
#include "ui/ui.hpp"
#include "ui/ui_element.hpp"

#endif
