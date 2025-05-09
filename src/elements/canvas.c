#include "canvas.h"
#include "../types.h"
#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TerResult CanvasAddObject(Canvas *canvas, Object *object) {
  if (canvas->objectCount >= canvas->objectsLen) {
    size_t newLen = (canvas->objectsLen == 0) ? 4 : canvas->objectsLen * 2;

    Object **newObjects = realloc(canvas->objects, newLen * sizeof(Object *));
    if (newObjects == NULL) {
      return TerErr;
    }

    canvas->objects = newObjects;
    canvas->objectsLen = newLen;
  }

  canvas->objects[canvas->objectCount] = object; // Store pointer
  canvas->objectCount++;

  return TerOk;
}

TerResult CanvasRemoveObject(Canvas *canvas, Object *object) {
  int objPos = -1;

  for (int i = 0; i < canvas->objectCount; i++) {
    if (canvas->objects[i] == object) {
      objPos = i;
      break;
    }
  }

  if (objPos == -1) {
    return TerErr;
  }

  for (int i = objPos; i < canvas->objectCount - 1; i++) {
    canvas->objects[i] = canvas->objects[i + 1];
  }

  canvas->objectCount--;

  return TerOk;
}
