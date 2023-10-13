# Debugging

## Data dumping

You can dump various objects, such as [vertices and matrices](vectors-matrices.md).

Start by including:
````c++
#inclued <opengl_msat/tools/dump.hpp>
````

Now simply do something like:

````c++
Vec3 a(3.0);

Dump::dump(a);
````

The coordinates of the vector will be logged to the console.

### System info
You can dump the system information with:

````c++
#include "opengl_msat/tools/system.hpp"

// ...

Window window;

// ...

Dump::dump(System::getSystemInformation(&window));
````