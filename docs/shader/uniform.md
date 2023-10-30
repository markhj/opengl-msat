# Shader uniforms

The ``ShaderProgram::uniform`` has many variants and features.

## Basic forms

The basic form takes a uniform location name and a value (of a specified type).

These are:

````c++
void uniform(std::string name, int value);
void uniform(std::string name, unsigned int value);
void uniform(std::string name, float value);
void uniform(std::string name, Vec3 value);
void uniform(std::string name, Vec4 value);
void uniform(std::string name, Mat4 value);
void uniform(std::string name, DirectionalLight value);
void uniform(std::string name, PointLight value);
void uniform(std::string name, SpotLight value);
void uniform(std::string name, Material value);
````

## Array forms
Almost all ``uniform`` variants also have a corresponding array version, where you specify the name of the uniform array, the index
you want to change, and then the value.

````c++
void uniform(std::string arrName, unsigned int index, int value);
void uniform(std::string arrName, unsigned int index, unsigned int value);
void uniform(std::string arrName, unsigned int index, float value);
void uniform(std::string arrName, unsigned int index, Vec3 value);
void uniform(std::string arrName, unsigned int index, Vec4 value);
void uniform(std::string arrName, unsigned int index, Mat4 value);
void uniform(std::string arrName, unsigned int index, DirectionalLight value);
void uniform(std::string arrName, unsigned int index, PointLight value);
void uniform(std::string arrName, unsigned int index, SpotLight value);
void uniform(std::string arrName, unsigned int index, Material value);
````

Example:
````c++
shader.uniform("pointLights", 8, somePointLight);
````

## Special forms
Lastly, there are two special forms:

### Camera
````c++
void uniform(Camera& camera);
````
This will set the camera information at the ``camera`` uniform location.

### Projection
````c++
void uniform(Projection& projection);
````
This sets the calculated projection-view-model at the ``projection`` location.

It also sets the ``camera``.
