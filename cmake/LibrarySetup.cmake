# The list of classes in the library
set(CLASSES
        animation/animation
        camera/camera
        camera/camera_roles
        controls/keyboard
        controls/keyboard_mapping
        controls/control_types
        controls/input_controller
        controls/mouse
        controls/mouse_mapping
        context/context
        geometry/vectors
        geometry/matrices
        geometry/shape2d
        geometry/shape3d
        geometry/rectangle
        geometry/cube
        geometry/object_wrapper
        geometry/object2d
        geometry/object3d
        geometry/object_collection
        math/math
        rendering/renderer
        rendering/renderstate
        rendering/framebuffer
        rendering/framebuffer_mng
        rendering/scrquad
        shader/shader
        shader/vertex_sbldr
        shader/fragment_sbldr
        shader/shader_builder
        tools/dump
        tools/grid
        tools/system
        tools/helper
        tools/service_provider
        text/font
        text/text
        textures/texture
        textures/texture2d
        textures/texture_unit_mng
        textures/material
        textures/cubemap
        textures/skybox
        timer/timer
        types/color
        types/image
        types/projections
        types/scenes
        types/vertex_types
        traits/handles_attributes
        traits/dev_messaging
        traits/loads_images
        traits/bindable
        traits/binding_mng
        vertex/vao
        vertex/vbo
        vertex/vbo_scene
        window/window
        ui/ui
        ui/ui_element)

# The list of structs
set(STRUCTS
    types/scenes)

# The list of contracts in the library
set(CONTRACTS
        animateable
        glm_derivative
        vertex_element
        vao_associable
        exports_vertices)

# Declare the variable which will contain the parsed lists
# of sources and headers
set(OPENGL_MSAT_HEADER_FILES "")
set(OPENGL_MSAT_SOURCE_FILES "")

# Iterate over the classes and append their header and source files to
# the respective variables
foreach(CLASS ${CLASSES})
    list(APPEND OPENGL_MSAT_HEADER_FILES "${PACKAGE_PREFIX_DIR}/include/opengl_msat/${CLASS}.hpp")
    list(APPEND OPENGL_MSAT_SOURCE_FILES "${PACKAGE_PREFIX_DIR}/src/opengl_msat/${CLASS}.cpp")
endforeach()

# Repeat the same for contracts (they only have header files)
foreach (CONTRACT ${CONTRACTS})
    list(APPEND OPENGL_MSAT_HEADER_FILES "${PACKAGE_PREFIX_DIR}/include/opengl_msat/contracts/${CONTRACT}.hpp")
endforeach ()

# Repeat the same for structs (they only have header files)
foreach (STRUCT ${STRUCTS})
    list(APPEND OPENGL_MSAT_HEADER_FILES "${PACKAGE_PREFIX_DIR}/include/opengl_msat/${STRUCT}.hpp")
endforeach ()

# Add the library with the source and header files
add_library(opengl_msat
        ${PACKAGE_PREFIX_DIR}/include/opengl_msat/common.h
        ${PACKAGE_PREFIX_DIR}/include/opengl_msat/public.hpp
        ${PACKAGE_PREFIX_DIR}/libs/glad/include/glad/glad.h
        ${PACKAGE_PREFIX_DIR}/libs/glad/src/glad.c
        ${PACKAGE_PREFIX_DIR}/libs/stb/stb_image.h
        ${OPENGL_MSAT_HEADER_FILES}
        ${OPENGL_MSAT_SOURCE_FILES})
