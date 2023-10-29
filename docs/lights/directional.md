# Directional light

A **directional light** is applied everywhere on a scene. It has only direction, not position.

## Prerequisites
* [Light basics](lights.md)

## Usage

Creating the light struct:
````c++
DirectionalLight directionalLight {
    .direction = Vec3(-1.0),
    .ambientColor = Color(0.1),
    .diffuseColor = Color(0.8),
    .specularColor = Color(0.7),
};
````

And the shader uniform values:
````c++
shader.uniform("numDirectionalLights", 1);
shader.uniform("directionalLights", 0, directionalLight);
````