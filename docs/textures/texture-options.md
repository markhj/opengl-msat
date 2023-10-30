# Texture options

You can modify a texture's options with ``applyOptions``. You don't need to bind before (or unbind after), this is done automatically.

## Usage
An example of using ``applyOptions``:
````c++
texture.applyOptions({
    .wrapping = TexturePattern::Repeat,    
});
````

## Options
This is a specification of the class ``TextureOptions``.

| Option | Data type | Default | Description                                      |
| --- | --- | --- |--------------------------------------------------|
| ``wrapping`` | ``TexturePattern`` | ``TexturePattern::Repeat`` | Behavior when texture coordinates exceed ``1.0`` |
| ``downSampling`` | ``TextureDownsampling`` | ``TextureDownsampling::Nearest`` | Texture down-sampling                            |
| ``upSampling`` | ``TextureSampling`` | ``TextureSampling::Nearest`` | Texture (up)sampling                             |
| ``format`` | ``TextureFormat`` | ``TextureFormat::RGB`` | Texture format                                   |
| ``mipmap`` | ``bool`` | ``false`` | Generate a mipmap                                |

See all available options from: [Texture enumerations](../lists/texture-enums.md).
