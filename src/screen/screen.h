#ifndef SCREEN_H
#define SCREEN_H
#include "../elements/canvas.h"
#include "../types.h"

typedef struct {
  unsigned int fps;
} ScreenConfig;

// Initialize the Screen and input handling
void ScreenInit(ScreenConfig config);

// Set the canvas which will be drawn by the screen
void ScreenSetCanvas(Canvas *canvas);

// Set the FPS amount at which the screen will be redrawn
void ScreenSetFps(unsigned int fps);

// Exit the screen, terminating the program
void ScreenExit();

#endif // !SCREEN_H
