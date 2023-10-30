# Texturing

In this example, we will demonstrate how to show a simple texture on the screen.

## Shader
You can use the [Fragment Shader Builder](../shader/fragment-shader-builder.md)
to create a shader source code which supports [materials](../textures/materials.md).

It could look something like this:

````c++
VertexShaderBuilder vsb(attributes);
vsb.projection = &projection;

FragmentShaderBuilder fsb(attributes);
fsb.materials();

ShaderProgram shader;
shader.fromBuilder(vsb);
shader.fromBuilder(fsb);
shader.compile();
````

## Scene
Now, we create a rectangle with texture coordinates and material (ID).

````c++
VAO vao;
VBO vbo;
vbo.setVertices({
    // Position         Texture coord.  // Material
    0.0, 0.0, 0.0,      0.0, 0.0,       0,
    1.0, 0.0, 0.0,      1.0, 0.0,       0,
    0.0, 1.0, 0.0,      0.0, 1.0,       0,

    0.0, 1.0, 0.0,      0.0, 3.0,       0,
    1.0, 0.0, 0.0,      3.0, 0.0,       0,
    1.0, 1.0, 0.0,      3.0, 3.0,       0,
});

vao.associate(vbo, attributes);
````

## Setting up materials
Now it's time to set up the materials.

We start by initializing the [Texture Unit Manager](../textures/tum.md) and 
loading a texture.

> The texture file must exist relative to the executeable

````c++
TextureUnitManager tum(&systemInfo);
Texture2D myTexture("assets/textures/my_texture.jpg");

// Create the texture slots in the shader
tum.attachShader(&shader);

// Bind texture to unit 3
// You can choose another number if you wish
tum.bindTextureTo(3, &myTexture);
````

Now, we create a material with ``myTexture`` set to the albedo.
````c++
Material material {
    .albedoTexture = &myTexture,
};
````

And then we apply this material as the value to ``materials[0]``.
Remember in the vertex definition where we configured the material to be 0?
This is the reference point.
````c++
shader.uniform("materials", 0, material);
````

## That's it!

If you render with the shader we've created here, you should now see
a rectangle standing at the center of the scene, with the texture on it.