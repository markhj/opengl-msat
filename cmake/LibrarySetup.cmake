set(CLASSES timer/timer)

set(OPENGL_MSAT_HEADER_FILES "")
set(OPENGL_MSAT_SOURCE_FILES "")

foreach(CLASS ${CLASSES})
    list(APPEND OPENGL_MSAT_HEADER_FILES "${PACKAGE_PREFIX_DIR}/include/opengl_msat/${CLASS}.hpp")
    list(APPEND OPENGL_MSAT_SOURCE_FILES "${PACKAGE_PREFIX_DIR}/src/opengl_msat/${CLASS}.cpp")
endforeach()

add_library(opengl_msat ${OPENGL_MSAT_HEADER_FILES} ${OPENGL_MSAT_SOURCE_FILES})
