# Point light

A **point light** is a local light that shines in all directions.

## Prerequisites
* [Light basics](lights.md)

## Usage

Creating the light struct:
````c++
PointLight pointLight {
    .position = Vec3(0.5, 0.3, 0.5),
    .ambientColor = Color(0.1),
    .diffuseColor = Color(0.8, 0.2, 0.8),
    .specularColor = Color(0.8, 0.2, 0.8)
};
````

And the shader uniform values:
````c++
shader.uniform("numPointLights", 1);
shader.uniform("pointLights", 0, pointLight);
````

## Additional properties

The point light offers some optional additional properties which can be configured:

| Property | Default   |
| --- |-----------|
| ``constant`` | ``1.0``   |
| ``linear`` | ``0.01``  |
| ``quadratic`` | ``0.032`` |