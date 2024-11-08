#ifndef OBJECT_H
#define OBJECT_H

// Object which can be drawn on a canvas
typedef struct {
  int width;
  int height;
  char **content;
  int color;
} Object;

// Macro for content inside object, every string is a new line
#define CONTENT(...) ((char *[]){__VA_ARGS__})

#endif // !OBJECT_H
