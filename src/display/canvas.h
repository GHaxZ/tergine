#ifndef CANVAS_H
#define CANVAS_H
#include "../types.h"
#include "object.h"

// Canvas where objects can be placed
typedef struct {
  int width;
  int height;
  int objectc;
  Object *objects;
} Canvas;

// Macro for canvas with specified width and height
#define CANVAS(WIDTH, HEIGHT)                                                  \
  (Canvas) { .width = WIDTH, .height = HEIGHT }

// Add an object for the specfied canvas at the specified position, returns
// TER_RES
TerResult CanvasAddObject(Canvas *canvas, Object *object, Position position);
#endif // !CANVAS_H
