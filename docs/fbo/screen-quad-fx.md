# Screen quad effects

## Prerequisites
- [Screen quad](screen-quad.md)

## Introduction
With relative ease you can apply various visual manipulations
on a ``ScreenQuad``.

## Usage
During (or before) a render loop, you can alter the ``grayscale`` and/or
``inverse`` properties of the screen quad.

The next time it renders, the effects will be applied.

Example:
````c++
screenQuad.grayscale = true;
````

## Properties
| Property      | Data type | Default | Description       |
|---------------| --- | --- |-------------------|
| ``grayscale`` | Boolean | ``false`` | Apply grayscaling |
| ``inverse``   | Boolean | ``false`` | Inverse colors    |