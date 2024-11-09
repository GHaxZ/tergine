#include "screen.h"
#include "locale.h"
#include <ncurses.h>
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static ScreenConfig screenConfig = {.fps = 0};
static Canvas *screenCanvas = NULL;

// Interval between screen redraws in microseconds
static int redrawInterval = 0;

static bool running = false;

// Private functions
// Draws the current canvas to the screen
void screenDraw() {}

// The main loop which keeps the screen refreshing
void screenLoop() {
  while (running) {
    screenDraw();

    usleep(redrawInterval);
  }
}

// Public functions
void ScreenInit(ScreenConfig config) {
  atexit(ScreenExit);
  signal(SIGSEGV, ScreenExit);
  signal(SIGABRT, ScreenExit);

  setlocale(LC_ALL, ""); // Set locale to support UTF-8

  initscr();             // Initialize the window
  noecho();              // Don't echo keypresses
  set_escdelay(0);       // Don't delay the ESC key;
  keypad(stdscr, true);  // Recognize function keys
  cbreak();              // Immediately feed input character to program
  curs_set(false);       // Don't display a cursor
  nodelay(stdscr, true); // Make getch() non-blocking

  clear();

  screenConfig = config;
  ScreenSetFps(config.fps);

  running = true;

  screenLoop();
}

void ScreenSetCanvas(Canvas *canvas) { screenCanvas = canvas; }

void ScreenSetFps(unsigned int fps) {
  screenConfig.fps = fps;
  redrawInterval = 1000000 / fps;
}

void ScreenExit() {
  running = false;
  endwin();
}
