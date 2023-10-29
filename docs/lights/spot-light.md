# Spot light

A **point light** is a local light with a direction.

## Prerequisites
* [Light basics](lights.md)

## Usage

Creating the light struct:
````c++
PointLight spotLight {
    .position = Vec3(1.0, 0.8, 1.0),
    .direction = Vec3(0.0, -1.0, 0.0),
    .ambientColor = Color(0.1),
    .diffuseColor = Color(0.0, 0.7, 0.8),
    .specularColor = Color(0.0, 0.7, 0.8),
};
````

And the shader uniform values:
````c++
shader.uniform("numSpotLights", 1);
shader.uniform("spotLights", 0, spotLight);
````

## Additional properties

The point light offers some optional additional properties which can be configured:

| Property      | Default   |
|---------------|-----------|
| ``constant``  | ``1.0``   |
| ``linear``    | ``0.01``  |
| ``quadratic`` | ``0.032`` |
| ``cutOff``    | ``12.0``  |

The ``cutOff`` value specifies how wide or narrow the light cone is in degrees.