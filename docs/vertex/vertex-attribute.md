# Vertex attributes

We provide a set of pre-defined common vertex attributes, which can be
used in conjunction with a number of features.

For example, they are used in ``VAO::associate`` to much more easily
set up the vertex attribute pointers.

## Attributes
| Enum             | Size | Description                        |
|------------------|------|------------------------------------|
| ``Position2D``   | 2    | Position in 2D space (x, y)        |
| ``Position3D``   | 3    | Position in 3D space (x, y, z)     |
| ``ColorRGB``     | 3    | RGB color value (red, green, blue) |
| ``TextureCoord`` | 2    | Texture coordinates in 2D (x, y)   |
| ``Normal2D``     | 2    | Vector normal in 2D                |
| ``Normal3D``     | 3    | Vector normal in 3D                |
| ``Tangent2D``    | 2    | Tangent in 2D                      |
| ``Tangent3D``    | 3    | Tangent in 3D                      |
| ``Bitangent2D``  | 2    | Bi-tangent in 2D                   |
| ``Bitangent3D``  | 3    | Bi-tangent in 3D                   |
