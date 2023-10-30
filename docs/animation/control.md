# Animation control

## Start/stop
You can start, stop, pause and resume animations (within a render loop),
with these functions:

````c++
void start();

void resume();

void pause();

void stop();

void rewind();
````

## Boolean values

````c++
bool isStarted();

bool isRunning();
````