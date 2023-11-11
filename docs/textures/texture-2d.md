# 2D texture

The ``Texture2D`` initializes ``Texture`` with ``TextureType::Texture2D`` pre-defined.

## Constructor

Texture can be generated either from an image file or as blank with specified dimensions.
Furthermore, it can be initialized with default or customized [texture options](texture-options.md).

````c++
Texture2D(std::string filename);

Texture2D(std::string filename, TextureOptions options);

Texture2D(unsigned int width, unsigned int height, TextureOptions options);

Texture2D(unsigned int width, unsigned int height);
````

## Save to file
You can save the texture to a file using the ``Texture2D::saveTo`` method.

Example:
````c++
texture.saveTo("file.png");
````

The output format is a PNG image, located relative to the executable.
