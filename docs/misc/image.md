# Image

The ``Image`` object contains data about a loaded image.

## Properties

| Property     | Data type          | Description           |
|--------------|--------------------|-----------------------|
| ``data``     | ``unsigned char*`` | Actual image contents |
| ``width``    | ``unsigned int``   | Width                 |
| ``height``   | ``unsigned int``   | Height                |
| ``channels`` | ``unsigned int``   | Color channels        |

## Loading images

Images can be loaded with the ``LoadsImages`` trait.

It contains the method ``loadImage``:

````c++
std::optional<Image> loadImage(std::string filename);
````

As can be seen it returns a ``std::optional<Image>``.
If it has no value, it failed to load the image. Typically because the
file doesn't exist. If it succeeds it returns the ``Image`` struct
populated with the data shown above.

An example of this implementation is in the [Texture class](../textures/textures.md).