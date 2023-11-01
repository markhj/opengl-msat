# OpenGL MSAT

**OpenGL MSAT** stands for **OpenGL misc. structs and tools**. The purpose of this library is to:

- Lessen the learning curve for OpenGL
- Reduce boilerplate code
- Abstract certain concepts so they're more digestible and less error prone

If you have any ideas or problems, don't hesitate to open an issue, or create a pull request.

## Current state of the project

:warning: **DO NOT USE IN PRODUCTION** :warning:

This library is being developed and shaped, and fundamental changes to the library's
foundation and features happen very rapidly.

It's highly unrecommended to use the library for any serious or real-world
purpose at this stage.

## Getting started :rocket:

To get started with OpenGL MSAT, please read the guide at: https://opengl-msat.readthedocs.io

## Documentation :blue_book:
The documentation is written in Markdown (MD) and compiled with MkDocs.

### Editing documentation (with mkdocs)
You must first and foremost have **Python** (and **PiP**) installed.
Proceed by installing **Mkdocs**.

For installation, please see: https://www.mkdocs.org

To serve the documentation locally:

````bash
mkdocs serve
````

On some Windows machines it might be necessary to run with:

````bash
python -m mkdocs serve
````

The documentation source is found in the ``docs`` directory.

### Publishing
The version hosted at readthedocs.io is automatically rebuilt when a new
version of ``master`` branch is pushed.

The documentation is based on the latest ``master`` branch, and is available
at https://opengl-msat.readthedocs.io

## Tests

The tests contained within the ``tests`` directory can be built using the
included ``CMakeLists.txt`` file and setting the environment variable
``OPENGL_MSAT_BUILD_TESTS`` to ``1`` or ``ON``.

This generates an executable which runs the tests suites.
