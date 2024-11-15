#ifndef SCREEN_H
#define SCREEN_H
#include "../elements/canvas.h"
#include "../types.h"

typedef struct {
  unsigned int fps;
} ScreenConfig;

// Run the Screen loop, calling the callback function every frame
void ScreenRun(void (*callback)());

// Set the canvas which will be drawn by the screen
void ScreenSetCanvas(Canvas *canvas);

// Set the FPS amount at which the screen will be redrawn
void ScreenSetFps(unsigned int fps);

// Play the terminal specific bell sound, returns TerErr in case terminal does
// not support bell sound
TerResult ScreenBeep();

// Exit the screen, terminating the program
void ScreenExit();

#endif // !SCREEN_H
