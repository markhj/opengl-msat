![OpenGL MSAT banner](https://res.cloudinary.com/drfztvfdh/image/upload/v1706440042/Github/opengl-msat_emha2y.jpg)

![GitHub Tag](https://img.shields.io/github/v/tag/markhj/opengl-msat?label=version)
![GitHub last commit](https://img.shields.io/github/last-commit/markhj/opengl-msat)
[![Documentation Status](https://readthedocs.org/projects/opengl-msat/badge/?version=latest)](https://opengl-msat.readthedocs.io/en/latest/?badge=latest)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/8b583492783549cf90ca12bace85b2c8)](https://app.codacy.com/gh/markhj/opengl-msat/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?label=license)

**OpenGL MSAT** stands for **OpenGL misc. structs and tools**. The purpose of this library is to:

- Soften the learning curve for OpenGL
- Reduce boilerplate code
- Abstract certain concepts so they're more digestible and less error prone

If you have any ideas or problems, don't hesitate to open an issue, or create a pull request.

# 🚀 Current state of the project

⚠️ **DO NOT USE IN PRODUCTION** ⚠️

This library is being developed and shaped, and fundamental changes to the library's
foundation and features happen very rapidly.

It's highly unrecommended to use the library for any serious or real-world
purpose at this stage.

# 🚦 Getting started

To get started with OpenGL MSAT, please read the guide at: <https://opengl-msat.readthedocs.io>

# 🌿 Features

- Window management
- 2D and 3D rendering
- Textures, cube maps and skyboxes
- Shader tools
- Lighting
- Models
- Font and text
- Framebuffers
- Misc. debugging tools
- UI

# 📌 Requirements

- C++17 or higher
- CMake 3.26 or higher
- Third-party libraries listed here: <https://opengl-msat.readthedocs.io/en/latest/getting-started/getting-started/>

# 📚 Documentation

The documentation is written in Markdown (MD) and compiled with MkDocs.

## Editing documentation (with mkdocs)

You must first and foremost have **Python** (and **PiP**) installed.
Proceed by installing **Mkdocs**.

For installation, please see: <https://www.mkdocs.org>

To serve the documentation locally:

````bash
mkdocs serve
````

On some Windows machines it might be necessary to run with:

````bash
python -m mkdocs serve
````

The documentation source is found in the ``docs`` directory.

## Publishing

The version hosted at readthedocs.io is automatically rebuilt when a new
version of ``master`` branch is pushed.

The documentation is based on the latest ``master`` branch, and is available
at <https://opengl-msat.readthedocs.io>

# 🎳 Tests

The tests contained within the ``tests`` directory can be built using the
included ``CMakeLists.txt`` file and setting the environment variable
``OPENGL_MSAT_BUILD_TESTS`` to ``1``.

This generates an executable which runs the tests suites.

> Important: C++ BBUnit must be discoverable with CMake's ``find_package`` to build tests.

# 🌱 Samples

You can compile the samples included in the ``samples`` directory, by adding
the environment variable ``OPENGL_MSAT_BUILD_SAMPLES`` and setting it to ``1``.
