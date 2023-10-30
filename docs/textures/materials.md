# Materials

The ``Material`` struct is used in various parts of OpenGL MSAT, for instance
in [texturing](textures.md) and [normal mapping](../lights/normal-mapping.md).

## Properties
| Property | Data type | Default  | Description               |
| --- | --- |----------|---------------------------|
| ``diffuseColor`` | ``Color`` | -        | Diffuse color             |
| ``albedoTexture`` | ``std::optional<Texture*>`` | -      | (Optional) albedo texture |
| ``shininess`` | ``float`` | ``32.0`` | Shininess factor          |

## How to use
To learn practical examples of using ``Material``, you can read: [Guide on texturing](../getting-started/texturing.md).