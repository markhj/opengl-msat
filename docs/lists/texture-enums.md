# Texture related enumerations

## Texture load status
| Enumeration                    | Description                                                                                      |
|--------------------------------|--------------------------------------------------------------------------------------------------|
| ``TextureLoadStatus::None``    | If no texture is loaded                                                                          |
| ``TextureLoadStatus::Partial`` | On objects with multiple textures, such as cubemaps, where at least one, but not all, are loaded |
| ``TextureLoadStatus::Success`` | If all textures are loaded                                                                       |

## Texture type
| Enumeration                | Description |
|----------------------------|-------------|
| ``TextureType::Texture2D`` | 2D texture  |
| ``TextureType::CubeMap``   | Cubemap     |

## Texture pattern

How should a texture behave when the coordinates are above ``1.0``.

| Enumeration                        | Description                 |
|------------------------------------|-----------------------------|
| ``TexturePattern::Repeat``         | Repeat (tiled)              |
| ``TexturePattern::RepeatMirrored`` | Repeat (tiled) but mirrored |
| ``TexturePattern::ClampToEdge``    | Clamp to edge               |
| ``TexturePattern::ClampToBorder``               | Clamp to border             |

## Texture format
| Enumeration                         | Description       |
|-------------------------------------|-------------------|
| ``TextureFormat::Red``              | Red               |
| ``TextureFormat::Green``            | Green             |
| ``TextureFormat::Blue``             | Blue              |
| ``TextureFormat::RGB``              | RGB color         |
| ``TextureFormat::RGBA``             | RGB + alpha color |
| ``TextureFormat::DepthComponent``   | Depth component   |
| ``TextureFormat::StencilComponent`` | Stencil component |
| ``TextureFormat::Luminance``                 | Luminance         |
| ``TextureFormat::LuminanceAlpha``            | Luminance + alpha |

## Texture (up)sampling
| Enumeration                  | Description |
|------------------------------|-------------|
| ``TextureSampling::Nearest`` | Nearest     |
| ``TextureSampling::Linear``  | Linear      |

## Texture downsampling
| Enumeration                            | Description           |
|----------------------------------------|-----------------------|
| ``TextureDownsampling::Nearest``       | Nearest               |
| ``TextureDownsampling::Linear``        | Linear                |
| ``TextureDownsampling::MipmapNearest`` | Nearest (from mipmap) |
| ``TextureDownsampling::MipmapLinear``  | Linear (from mipmap)  |