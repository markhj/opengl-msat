cmake_minimum_required(VERSION 3.26)
project(opengl_msat)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(libs/glad/include)
include_directories(libs/stb)

# LibrarySetup.cmake needs the variable PACKAGE_PREFIX_DIR
# In this case we just set it to the current directory
set(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}")
include(cmake/LibrarySetup.cmake)
include(cmake/ThirdPartyLibs.cmake)

# Set the option OPENGL_MSAT_BUILD_TESTS depending on the environment
# variable of the same name
set(OPENGL_MSAT_BUILD_TESTS OFF)
if (DEFINED ENV{OPENGL_MSAT_BUILD_TESTS})
    set(OPENGL_MSAT_BUILD_TESTS $ENV{OPENGL_MSAT_BUILD_TESTS})
endif ()

# Build tests (if requested by the env. variable OPENGL_MSAT_BUILD_TESTS)
if (OPENGL_MSAT_BUILD_TESTS)
    set(TEST_CASES
        texture_tests
        math_tests)

    set(OPENGL_MSAT_TEST_FILES "")
    foreach (TEST_CASE ${TEST_CASES})
        list(APPEND OPENGL_MSAT_TEST_FILES "tests/cases/${TEST_CASE}.hpp")
        list(APPEND OPENGL_MSAT_TEST_FILES "tests/cases/${TEST_CASE}.cpp")
    endforeach ()

    include_directories(libs/bbunit)
    add_executable(tests
            tests/main.cpp
            ${OPENGL_MSAT_TEST_FILES})
    target_link_libraries(tests opengl_msat)
endif()
