#include "screen.h"
#include "locale.h"
#include <ncurses.h>
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static ScreenConfig screenConfig = {.fps = 20};
static Canvas *screenCanvas = NULL;

// Interval between screen redraws in microseconds
static int redrawInterval = 0;

static bool running = false;

// Private functions
// Draws the current canvas to the screen
void screenDraw() {
  if (screenCanvas == NULL) {
    return;
  }

  clear();

  for (int x = 0; x < screenCanvas->objectCount; x++) {
    Object *obj = &screenCanvas->objects[x];

    int i = 0;
    while (obj->content[i] != NULL) {
      mvprintw(obj->position.y + i, obj->position.x, "%s", obj->content[i]);
      i++;
    }
  }

  refresh();
}

// The main loop which keeps the screen refreshing
void screenLoop(void (*callback)()) {
  while (running) {
    screenDraw();
    callback();

    usleep(redrawInterval);
  }
}

// Public functions
void ScreenRun(void (*callback)()) {
  atexit(ScreenExit);
  signal(SIGSEGV, ScreenExit);
  signal(SIGABRT, ScreenExit);

  setlocale(LC_ALL, ""); // Set locale to support UTF-8

  initscr();             // Initialize the window
  start_color();         // Enable colors
  use_default_colors();  // Use default terminal background color
  noecho();              // Don't echo keypresses
  set_escdelay(0);       // Don't delay the ESC key;
  keypad(stdscr, true);  // Recognize function keys
  cbreak();              // Immediately feed input character to program
  curs_set(false);       // Don't display a cursor
  nodelay(stdscr, true); // Make getch() non-blocking

  clear();

  running = true;

  screenLoop(callback);
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
