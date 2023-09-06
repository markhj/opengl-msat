include(CMakePackageConfigHelpers)

# Store the absolute path to the root of the library in PACKAGE_PREFIX_DIR
get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

# Set up the header and sources as a library
include(${PACKAGE_PREFIX_DIR}/cmake/LibrarySetup.cmake)

# Ensure the "include" directory is accessible to the client project
target_include_directories(opengl_msat
        PUBLIC
        $<BUILD_INTERFACE:${PACKAGE_PREFIX_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_include_directories(opengl_msat
        PUBLIC
        $<BUILD_INTERFACE:${PACKAGE_PREFIX_DIR}/libs/glad/include>
        $<INSTALL_INTERFACE:libs/glad/include>
)

# Export the targets file
export(TARGETS opengl_msat
        FILE ${CMAKE_CURRENT_BINARY_DIR}/opengl_msatTargets.cmake)

# Install CMake files
install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/opengl_msatConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/opengl_msatConfigVersion.cmake"
        DESTINATION lib/cmake/opengl_msat
)

# Load third-party libraries
include(${PACKAGE_PREFIX_DIR}/cmake/ThirdPartyLibs.cmake)
