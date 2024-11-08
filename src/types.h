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

// Macro for creating a position
#define POSITION(X, Y)                                                         \
  (Position) { .x = X, .y = Y }

#endif // !TYPES_H
