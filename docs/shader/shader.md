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

These shader stages are available from ``shared/shader_types.hpp``:

| Stage                        | Description             |
|------------------------------|-------------------------|
| ``ShaderStage::Vertex``      | Vertex                  |
| ``ShaderStage::Fragment``    | Fragment                |
| ``ShaderStage::Geometry``    | Geometry                |
| ``ShaderStage::Compute``     | Compute                 |
| ``ShaderStage::TessEval``    | Tessellation evaluation |
| ``ShaderStage::TessControl`` | Tessellation control    |