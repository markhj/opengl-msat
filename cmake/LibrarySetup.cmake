# The list of classes in the library
set(CLASSES
        bindable/bindable
        shared/keyboard_types
        shared/vertex_types
        camera/camera
        controls/keyboard
        controls/keyboard_mapping
        context/context
        geometry/vectors
        geometry/matrices
        geometry/shape
        geometry/rectangle
        geometry/cube
        geometry/object_wrapper
        geometry/object2d
        geometry/object3d
        geometry/object_collection
        math/math
        renderer/renderer
        renderer/renderstate
        shader/shader
        shader/vertex_sbldr
        shader/fragment_sbldr
        shader/shader_builder
        tools/dump
        tools/grid
        tools/system
        timer/timer
        types/color
        vertex/vao
        vertex/vbo
        window/window)

# The list of structs
set(STRUCTS
    scenes)

# The list of contracts in the library
set(CONTRACTS
        glm_derivative
        vertex_element
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
    list(APPEND OPENGL_MSAT_HEADER_FILES "${PACKAGE_PREFIX_DIR}/include/opengl_msat/shared/${STRUCT}.hpp")
endforeach ()

# Add the library with the source and header files
add_library(opengl_msat
        ${PACKAGE_PREFIX_DIR}/include/opengl_msat/common.h
        ${PACKAGE_PREFIX_DIR}/libs/glad/include/glad/glad.h
        ${PACKAGE_PREFIX_DIR}/libs/glad/src/glad.c
        ${OPENGL_MSAT_HEADER_FILES}
        ${OPENGL_MSAT_SOURCE_FILES})
