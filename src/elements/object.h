#ifndef OBJECT_H
#define OBJECT_H
#include "../types.h"

// Object which can be drawn on a canvas
typedef struct {
  Position position;
  char **content;
  Color color;
} Object;

// Macro for content inside object, every string is a new line
#define CONTENT(...) ((char *[]){__VA_ARGS__, NULL})

#define OBJECT(POSITION, CONTENT, COLOR)                                       \
  (Object) { .position = POSITION, .content = CONTENT, .color = COLOR }

#endif // !OBJECT_H
