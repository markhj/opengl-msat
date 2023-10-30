# Going 3D
Going from [the white 2D triangle](first-app.md) to 3D, requires only a few steps.

- Use 3D [vertex attribute(s)](../vertex/vertex-attribute.md)
- Use [perspective projection](../lists/projections.md)
- Provide vertex data suitable for new VAO structure

On top of adding 3D, we will also make the color customizable.
In other words: We're going to end up with the 'rainbow triangle'.

## Prerequisites

This tutorial will probably only make sense, if you've read
the [First app](first-app.md) chapter. We're going
to skip over some details covered in that guide, but this example is built
on top of it.

## VAO
First and foremost, we're going to make changes to the list of vertex attributes:

````c++
std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D, VertexAttribute::ColorRGB };
````

We changed from ``Position2D`` to ``Position3D``. We also added ``ColorRGB``.

## Camera
The ``Camera`` class is instantiated with the [Window](../window/window.md) instance.

````c++
Camera camera(window);
````

Optionally, you can set an initial position and target.

````c++
camera.setPosition(Vec3(1.0));
camera.setTarget(Vec3(0.0));
````

## VBO (vertex data)
Compared to the white 2D triangle, we're going to "upgrade"
to 3D coordinates, as well as adding colors.

This means that every vertex pair now consists of six values,
compared to only two.

````c++
VBO vbo({
    // Position         // Color
    -0.5, -0.5, 0.0,    1.0, 0.0, 0.0,
    0.5, -0.5, 0.0,     0.0, 1.0, 0.0,
    0.0, 0.5, 0.0,      0.0, 0.0, 1.0
});
````

## Projection / perspective
We can quite easily instruct our vertex shader builder to 
write a source code which supports perspective projection:

````c++
VertexShaderBuilder vsb(attributes);

vsb.setProjection(Projection::Perspective);

// Initialize shader, etc.
shader.fromBuilder(vsb);
````

## Initialize renderer
We're also going to add [Timer](../misc/timer.md) and [RenderSettings](../render/render-settings.md) to
the instantiation of the ``Renderer``.

````c++
Timer timer;
RenderSettings renderSettings;
Renderer renderer(window, &timer, &renderSettings);
````

## Render loop
We also have an addition in the render loop, namely we're going to
pass some uniform values to the shader (which are calculated by the camera):

````c++
shader.uniform(camera);
````

This step is required to make the calculations performed in the shader aware
of changes to the camera (its position, what it looks at, etc.).

## Full program
A full program (with camera rotation).

The parts with comments are the changes compared to the 2D triangle example.

````c++
#include <opengl_msat/public.hpp>

int main()
{
    Window window(800, 600, "OpenGL MSAT");
    window.generate();
    
    // Vertex attributes modified to hold 3D position and color
    std::vector<VertexAttribute> attributes = { VertexAttribute::Position3D, VertexAttribute::ColorRGB };

    ShaderProgram shader;
    
    // Vertex Shader Builder instructed to apply a perspective projection
    shader.fromBuilder(VertexShaderBuilder(attributes).setProjection(Projection::Perspective));
    shader.fromBuilder(FragmentShaderBuilder(attributes));
    shader.compile();

    VAO vao;
    
    // VBO data updated to contain 3D positions and colors
    VBO vbo({
        // Position         // Color
        -0.5, -0.5, 0.0,    1.0, 0.0, 0.0,
        0.5, -0.5, 0.0,     0.0, 1.0, 0.0,
        0.0, 0.5, 0.0,      0.0, 0.0, 1.0
    });
    vao.associate(vbo, attributes);

    // Timer and RenderSettings added to Renderer
    Timer timer;
    RenderSettings renderSettings;
    Renderer renderer(window, &timer, &renderSettings);

    // Variables to keep track of camera animation
    float s = 0.0, dist = 2.0;

    // Initialize camera and set its target (what it looks at)
    Camera camera(window);
    camera.setTarget(Vec3(0.0));

    renderer.loop([&](Renderer* renderer) {
        // Increase s by delta time
        s += timer.getDeltaTime();

        // Set new camera position
        camera.setPosition(Vec3(sin(s) * dist, 0.0, cos(s) * dist));

        // Send new information about camera position, etc. to the shader
        shader.uniform(camera);
        shader.bind();

        renderer->render(vao);
    });

    return 0;
}
````