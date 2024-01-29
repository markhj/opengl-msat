# Getting started

## Required third-party libraries
A number of third-party libraries are required for OpenGL MSAT to function. These are:

- GLFW
- OpenGL
- GLM
- Assimp
- Freetype

If you don't know how to install or link these libraries, you need to do this before anyting else.

### Building with tests
> To build the **test suite** of OpenGL MSAT itself, you additionally require C++ BBunit:
> https://github.com/markhj/cpp-bbunit.
> This library must be discoverable via CMake's ``find_package``.

## Getting started using CMake
Clone the library from: https://github.com/markhj/opengl-msat to somewhere on your local machine.

To add OpenGL MSAT as a third-party library to your client application, you should
first and foremost declare a variable explaining to CMake where you've installed the library.

The variable is typically required to be: ``opengl_msat_DIR``

There are different ways of declaring this variable so your application's CMake file
can read it, which depends on your IDE or if you use CMake by command line.

You can see if the variable is correctly declared and readable by logging its contents with

````cmake
message("OpenGL MSAT: ${opengl_msat_DIR}")
````

If the output is empty in the CMake-specific console, then it's not correctly set.

## CMakeLists.txt
Once the variable becomes readable, you can add this to your ``CMakeLists.txt`` file:
````cmake
find_package(opengl_msat REQUIRED)

# add_executable() and other configurations

target_link_libraries(your_app_name opengl_msat)
````

**Important:** Including OpenGL MSAT will _also_ include
GLFW, OpenGL, GLM and other libraries in your project.

## Coding time!
And that should be it! You're now set to start using the classes and tools
bundled in OpenGL MSAT.