# The list of classes in the library
set(CLASSES
        shared/keyboard_types
        controls/keyboard
        controls/keyboard_mapping
        context/context
        timer/timer
        vertex/vao
        vertex/vbo
        window/window)

# The list of contracts in the library
set(CONTRACTS
        bindable)

# The list of structs and enums
set(SHARED_TYPES
        vertex_types
        keyboard_types)

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

# Repeat the same for contracts (they only have header files)
#foreach (SHARED_TYPE ${SHARED_TYPES})
#    list(APPEND OPENGL_MSAT_HEADER_FILES "${PACKAGE_PREFIX_DIR}/include/opengl_msat/shared/${SHARED_TYPE}.hpp")
#endforeach ()

# Add the library with the source and header files
add_library(opengl_msat
        ${PACKAGE_PREFIX_DIR}/include/opengl_msat/common.h
        ${PACKAGE_PREFIX_DIR}/libs/glad/include/glad/glad.h
        ${PACKAGE_PREFIX_DIR}/libs/glad/src/glad.c
        ${OPENGL_MSAT_HEADER_FILES}
        ${OPENGL_MSAT_SOURCE_FILES})
