# Shader

A **shader program** consists of one or more **shader stages**, typically vertex and fragment.

## Include
````c++
#include <opengl_msat/shader/shader.hpp>
````

## Shader program

You can easily set up and compile a shader program like this:

````c++
const char* vertexShaderSource = R"( ... )";
const char* fragmentShaderSource = R"( ... )";

ShaderProgram shader;
shader.setSource(ShaderStage::Vertex, vertexShaderSource);
shader.setSource(ShaderStage::Fragment, fragmentShaderSource);
shader.compile();
````

Compilation and linking errors will be logged to the console.

## Shader stages

See list of available shader stages from: [Shader stages](../lists/shader-stage.md)