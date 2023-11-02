/**
 * Sample: Hello Triangle!
 *
 * This tiny sample demonstrates how to create a window, a standard shader, VAO and VBO,
 * an instance of Renderer, and how to display a simple colored 2D triangle on the screen.
 */

#include "opengl_msat/public.hpp"

int main()
{
    // Create a 800x600 window
    Window window(800, 600, "Hello Triangle!");
    window.generate();

    // Define the vertex attributes needed, in this case 2D position (x,y) and RGB color
    std::vector<VertexAttribute> attributes = { VertexAttribute::Position2D, VertexAttribute::ColorRGB };

    // Create a basic shader using the Vertex and Fragment Shader Builders
    // with their basic configurations
    ShaderProgram shader;
    shader.fromBuilder(VertexShaderBuilder(attributes));
    shader.fromBuilder(FragmentShaderBuilder(attributes));
    shader.compile();

    // Create VAO and VBO
    // and define a simple 2D triangle in rainbow colors
    VAO vao;
    VBO vbo;
    vbo.setVertices({
        0.0, 0.5,       1.0, 0.0, 0.0,
        -0.5, -0.5,     0.0, 1.0, 0.0,
        0.5, -0.5,      0.0, 0.0, 1.0,
    });
    vao.associate(vbo, attributes);

    // Set up timer and camera, and create the instance of Renderer
    Timer timer;
    Camera camera;
    Renderer renderer(&window, &camera, &timer);

    renderer.loop([&](Renderer* renderer) {
        // Use the shader
        shader.bind();

        // Render
        renderer->render(vao);
    });

    return 0;
}