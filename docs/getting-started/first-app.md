# First app

The simplest program you can write with OpenGL MSAT that makes just a tiny
bit of sense is one displaying a white 2D triangle.

## Include
Start by including the necessary libraries and set up the ``main`` function.

````c++
#include <opengl_msat/window/window.hpp>
#include <opengl_msat/vertex/vao.hpp>
#include <opengl_msat/vertex/vbo.hpp>
#include <opengl_msat/renderer/renderer.hpp>
#include <opengl_msat/shader/shader.hpp>
#include <opengl_msat/shader/vertex_sbldr.hpp>
#include <opengl_msat/shader/fragment_sbldr.hpp>

int main()
{
    // ...
    
    return 0;
}
````

## Window
We start by creating the (GLFW) [window instance](/getting-started/window).
````c++
Window window(800, 600, "OpenGL MSAT");
window.generate();
````
You can change the dimensions and window title.

## Attributes
Next, we need to define the [vertex attributes](/vertex/vertex-attribute) which are used across
several components of the OpenGL MSAT library to ensure streamlined data structures
across vertex data, shaders, etc.
````c++
std::vector<VertexAttribute> attributes = { VertexAttribute::Position2D };
````
For this example we just need a 2D position. We don't need the Z-axis, and we don't
need color, because we've already decided it should just be plain white.

## Shader
Becauase our program is so simple, we don't need anything fancy for the
[vertex](/shader/vertex-shader-buider) or [fragment shader builders](/shader/fragment-shader-builder).

All they need to fulfill the criteria to render a white 2D triangle, is the existence of the 2D position
(which is provided via the ``attributes`` variable defined earlier).

````c++
ShaderProgram shader;
shader.fromBuilder(VertexShaderBuilder(attributes));
shader.fromBuilder(FragmentShaderBuilder(attributes));
shader.compile();
shader.bind();
````

## VAO & VBO
Now, we initialize the [VAO](/vertex/vao) and [VBO](/vertex/vbo), and associate them.

````c++
VAO vao;
VBO vbo({ -0.5, -0.5, 0.5, -0.5, 0.0, 0.5 });
vao.associate(vbo, attributes);
````

The constructor of the VBO contains the vertex data. It's not necessary to provide them via the constructor,
but one of several ways to do it.

## Render loop
Now it's time to set up the [Renderer](/render/render).
In its simplest form it just takes the ``Window`` instance.

````c++
Renderer renderer(window);

renderer.loop([&](Renderer* renderer) {
    renderer->render(vao);
});
````

For this simple example, we only need to render a single VAO.

## The full program
When everything is put together, we get the code below.
It should generate a window and display a white triangle.

````c++
#include <opengl_msat/window/window.hpp>
#include <opengl_msat/vertex/vao.hpp>
#include <opengl_msat/vertex/vbo.hpp>
#include <opengl_msat/renderer/renderer.hpp>
#include <opengl_msat/shader/shader.hpp>
#include <opengl_msat/shader/vertex_sbldr.hpp>
#include <opengl_msat/shader/fragment_sbldr.hpp>

int main()
{
    Window window(800, 600, "OpenGL MSAT");
    window.generate();
    
    std::vector<VertexAttribute> attributes = { VertexAttribute::Position2D };

    ShaderProgram shader;
    shader.fromBuilder(VertexShaderBuilder(attributes));
    shader.fromBuilder(FragmentShaderBuilder(attributes));
    shader.compile();
    shader.bind();

    VAO vao;
    VBO vbo({ -0.5, -0.5, 0.5, -0.5, 0.0, 0.5 });
    vao.associate(vbo, attributes);

    Renderer renderer(window);

    renderer.loop([&](Renderer* renderer) {
        renderer->render(vao);
    });

    return 0;
}

````