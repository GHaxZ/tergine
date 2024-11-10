#ifndef TYPES_H
#define TYPES_H

// Result type for functions that can fail
typedef enum {
  TerOk,
  TerErr,
} TerResult;

// Position in a 2D space
typedef struct {
  int x;
  int y;
} Position;

// Dimension in a 2D space
typedef struct {
  int width;
  int height;
} Dimension;

// RGB Color
typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Color;

//  TODO: Finish color definitions and conversion
#define COLOR(R, G, B)                                                         \
  (Color) { .r = R, .g = G, .b = B }

// Macro for creating a position
#define POSITION(X, Y)                                                         \
  (Position) { .x = X, .y = Y }

// Macro for creating a position
#define DIMENSION(WIDTH, HEIGHT)                                               \
  (Dimension) { .width = WIDTH, .height = HEIGHT }

#endif // !TYPES_H
