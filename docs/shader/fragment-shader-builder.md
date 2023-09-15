# Fragment shader builder

## Include, initialize and usage
````c++
#include <opengl_msat/shader/fragment_sbldr.hpp>

std::vector<VertexAttribute> attributes = { /* List of vertex attributes */ };

FragmentShaderBuilder fsb(attributes);

// Apply settings to fragment shader builder

// Other initializations

ShaderProgram shader;
// ...
shader.fromBuilder(fsb);
````

## Configuration

In the current version of OpenGL MSAT, the Fragment Shader Builder
doesn't provide any configurations.
