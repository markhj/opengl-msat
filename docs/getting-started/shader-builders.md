# Shader builders

**Shaders builders** are classes which help with creating relatively
basic shader programs (without having to specifically code them).

## How it works
They work by providing [the vertex attribute structure](../vertex/vertex-attribute.md),
and then a number of optional commands.

Based on this a builder will 
create the source code for the shader. It can be passed directly into
the [Shader class](../shader/shader.md) with the ``fromBuilder`` method.

````c++
std::vector<VertexAttribute> attributes = { /* List of attributes */ };

VertexShaderBuilder vsb(attributes);
FragmentShaderBuilder fsb(attributes);

ShaderProgram shader();
shader.fromBuilder(vsb);
shader.fromBuilder(fsb);
shader.compile();
````

## Use cases
The shader builders can only lift relatively simple tasks, and are only truly
suitable to ease the learning curve for beginners.
