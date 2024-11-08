#include "canvas.h"
#include "../types.h"
#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TerResult CanvasAddObject(Canvas *canvas, Object *object, Position position) {
  Object *new_objects = malloc((canvas->objectc + 1) * sizeof(Object));
  if (new_objects == NULL) {
    return TerErr;
  }

  memcpy(new_objects, canvas->objects, canvas->objectc * sizeof(Object));

  new_objects[canvas->objectc] = *object;

  free(canvas->objects);

  canvas->objects = new_objects;
  canvas->objectc += 1;

  return TerOk;
}
