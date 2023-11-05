# ``CursorMoved``

``CursorMoved`` is a struct usually passed to cursor movement event handlers.

It contains four properties:

| Property  | Data type | Description                                                                          |
|-----------| --- |--------------------------------------------------------------------------------------|
| ``x``     | ``unsigned int`` | The X-coordinate of the cursor (constrained to the window)                           |
| ``y``     | ``unsigned int`` | The Y-coordinate of the cursor (constrainted to the window)                          |
| ``diffX`` | ``int`` | The change of the cursor on the X-axis (negative: moved left, positive: moved right) |
| ``diffY`` | ``int`` | The change of the cursor on the Y-axis (negative: moved up, positive: moved down)    |