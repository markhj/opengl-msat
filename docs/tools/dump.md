# Dump objects

The ``Dump`` class can easily write information about a number
of classes to the console.

## Support
It currently supports:

- ``Vec2``, ``Vec3``, ``Vec4``
- ``Mat4``
- ``SystemInfo``

## Usage
You can dump an object with:

````c++
Vec3 vec3(1.0, 2.0, 3.0);

Dump::dump(vec3);
````