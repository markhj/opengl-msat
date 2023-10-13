# Vertex shader builder

## Include, initialize and usage
````c++
#include <opengl_msat/shader/vertex_sbldr.hpp>

std::vector<VertexAttribute> attributes = { /* List of vertex attributes */ };

VertexShaderBuilder vsb(attributes);

// Apply settings to fragment shader builder

// Other initializations

ShaderProgram shader;
// ...
shader.fromBuilder(vsb);
````

## Configuration
### Projection

You can set the perspective of the vertex shader with ``setProjection``.
You can provide enumeration values from [Projections enum](../lists/projections.md).

For instance:

````c++
vsb.setProjection(Projection::Perspective);
````

#### Note on perspective projection
When setting projection to ``Projection::Perspective``
you also need to provide model, view and projection calculations
for rendering.

You can do this with the ``Shader`` class ``uniform`` method,
which automatically picks the values it needs from the ``Camera`` instance.

````c++
shader.uniform(camera);
````

You can learn more about this in [Going 3D](../getting-started/going-3d.md).
