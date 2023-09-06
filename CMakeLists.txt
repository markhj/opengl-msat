cmake_minimum_required(VERSION 3.26)
project(opengl_msat)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# LibrarySetup.cmake needs the variable PACKAGE_PREFIX_DIR
# In this case we just set it to the current directory
set(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}")
include(cmake/LibrarySetup.cmake)
include(cmake/ThirdPartyLibs.cmake)
