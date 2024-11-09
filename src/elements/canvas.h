#ifndef CANVAS_H
#define CANVAS_H
#include "../types.h"
#include "object.h"
#include <stddef.h>

// Canvas where objects can be placed
typedef struct {
  Dimension size;
  int objectCount;
  Object *objects;
  size_t objectsLen;
} Canvas;

// Macro for canvas with specified width and height
#define CANVAS(WIDTH, HEIGHT)                                                  \
  (Canvas) { DIMENSION(WIDTH, HEIGHT) }

// Add an object on the specfied canvas returns TER_REScan
TerResult CanvasAddObject(Canvas *canvas, Object *object);
#endif // !CANVAS_H
