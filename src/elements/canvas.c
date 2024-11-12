#include "canvas.h"
#include "../types.h"
#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TerResult CanvasAddObject(Canvas *canvas, Object *object) {
  if (canvas->objects == NULL || canvas->objectCount >= canvas->objectsLen) {
    int newLen = (canvas->objectsLen == 0) ? 4 : canvas->objectsLen * 2;

    Object *newObjects = realloc(canvas->objects, newLen * sizeof(Object));
    if (newObjects == NULL) {
      return TerErr;
    }

    canvas->objects = newObjects;
    canvas->objectsLen = newLen;
  }

  canvas->objects[canvas->objectCount] = *object;

  canvas->objectCount++;

  return TerOk;
}

TerResult CanvasRemoveObject(Canvas *canvas, Object *object) {
  int objPos = 0;

  while (objPos < canvas->objectCount) {
    Object *canvasObj = &canvas->objects[objPos];

    if (object == canvasObj) {
      for (int x = objPos; x < canvas->objectCount - 1; x++) {
        canvas->objects[x] = canvas->objects[x + 1];
      }

      canvas->objectCount--;

      return TerOk;
    }

    objPos++;
  }

  return TerErr;
}
