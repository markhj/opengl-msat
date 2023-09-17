# System information

Often, you need to structure your code in accordance with system-specific information, ranging from screen resolution to max. number of texture units.

## Include
````c++
#include "opengl_msat/tools/system.hpp"
````

## Usage
````c++
SystemInfo systemInfo = System::getSystemInfo(&window);
````

**Important:** Window must be initialized first, otherwise the program
may hang.

Now you can retrieve information, for example:

````c+
std::cout << systemInfo.maxTextureUnits << std::endl;
````

## Dump

You can use the ``Dump::dump`` method to retrieve the complete list
of information:

````c++
Dump::dump(System::getSystemInfo(&window));
````

## List of options

| Key                       | Type             | Description         |
|---------------------------|------------------|---------------------|
| ``openGLVersion.version`` | ``const char*``  | Full version        |
| ``openGLVersion.major``   | ``unsigned int`` | Major version       |
| ``openGLVersion.minor``   | ``unsigned int`` | Minor version       |
| ``gpu.name``              | ``const char*``  | GPU name            |
| ``gpu.vender``            | ``const char*``  | GPU vendor          |
| ``gpu.driverVersion``     | ``const char*``  | GPU driver (version) |
| ``maxTextureUnits``       | ``int``          | Max. texture units  |