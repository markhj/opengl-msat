# Framebuffer manager

You can initialize a ``FramebufferManager`` to ease the control of binding to framebuffers.

## Initialize
The ``FramebufferManager`` requires only an instance of ``SystemInfo`` to instantiate.

````c++
FramebufferManager fm(&systemInfo);
````

## Max. framebuffers
You can retrieve the maximum number of framebuffers, which can be different between systems, with:

````c++
std::cout << "Max. framebuffers: " << fm.getAvailableSlots() << std::endl;
````

## Binding and unbinding
You can bind to a framebuffer with:
````c++
fm.bindTo(6);
````

This will bind the to the 7th framebuffer.

Remember that "unbinding" means you return to the default framebuffer.

````c++
fm.unbind();
````

So, it's equivalent to ``fm.bindTo(0);``.


## Current binding
You can retrieve the currently bound framebuffer with ``getBoundTo``:

````c++
std::cout << "Currently bound to framebuffer: " << fm.getBoundTo() << std::endl;
````

## ``with``

To achieve more readable and safer scope control, you can use the ``with`` method, which carries out
the actions of a lambda function while bound to a specific framebuffer, and then unbinds.

````c++
fm.with(4, [&]() {
    // Actions for framebuffer 5
});
````
