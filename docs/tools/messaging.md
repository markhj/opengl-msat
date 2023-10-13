# Messaging

Various parts of the OpenGL MSAT system may want to communicate with you
when there are peculiarities or errors you should be aware of.

But to avoid imposing on your actual application, you can define the behavior
of different logging/messaging levels.

You can also use the ``DeveloperMessaging`` trait yourself.

## Configuring behavior

Simply modify the public static properties of ``DeveloperMessaging``.

````c++
DeveloperMessaging::noticeBehavior = MessagingBehavior::StdCout;
DeveloperMessaging::warningBehavior = MessagingBehavior::StdCerr;
DeveloperMessaging::criticalBehavior = MessagingBehavior::ThrowException;
````

## Levels

* **Notice**: Something that may have a minor impact on rendering, but should still work somewhat accurately
* **Warning**: Something that may cause the rendering to behave very strangely, or not work at all
* **Critical**: Something that can cause the application to crash

## Options

| Property | Default                           |
|----------|-----------------------------------|
| ``Silent``     | Do nothing                        |
| ``StdCout``     | Log to console with ``std::cout`` |
| ``StdCerr``     | Log to console with ``std::cerr`` |
| ``ThrowException``     | Throw exception                   |

## Default options

| Level    | Option              |
|----------|---------------------|
| Notice   | ``StdCout ``        |
| Warning  | ``StdCerr ``        |
| Critical | ``ThrowException `` |