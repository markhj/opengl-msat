# Adding lights

By using the [Fragment Shader Builder](../shader/fragment-shader-builder.md) it's quite
easy to get simple lights in OpenGL MSAT.

> In this example, it's assumed you can set up your own simple scene for demonstration. For instance, by creating a cube or 
> a similar simple scene.

## Setting up

A typical setup with vertex and fragment shader builders would look like this.

The important thing to take note of is that we call the ``lighting`` method
on ``fsb`` (Fragment Shader Builder).

This adds lighting logic in the shader code.

````c++
VertexShaderBuilder vsb(attributes);
vsb.projection = &projection;

FragmentShaderBuilder fsb(attributes);
fsb.lighting();

ShaderProgram shader;
shader.fromBuilder(vsb);
shader.fromBuilder(fsb);
shader.compile();
````

## Creating a light

There are three types of lights in OpenGL MSAT. To learn more about them
individually, you can read the chapter on [lighting basics](../lights/lights.md).

In this example, we will simply add a [directional light](../lights/directional.md).

````c++
DirectionalLight directionalLight {
    .direction = Vec3(-1.0, -1.0, -1.0),
    .ambientColor = Color(0.1, 0.1, 0.1),
    .diffuseColor = Color(0.8),
    .specularColor = Color(0.8, 0.5, 0.4),
};
````

And let's not forget to update the two shader uniform values which
explain that there will be one directional light:

````c++
shader.uniform("numDirectionalLights", 1);
shader.uniform("directionalLights", 0, directionalLight);
````

## That's it!

And that's actually all you need to implement a light.

Don't forget to render your scene with the shader we built in the beginning.