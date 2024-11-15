#include "screen.h"
#include "locale.h"
#include <math.h>
#include <ncurses.h>
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static ScreenConfig screenConfig = {
    .fps = 20, .canvas = NULL}; // Include canvas in ScreenConfig

// Interval between screen redraws in microseconds
static int redrawInterval = 0;

static bool running = false;

// Private functions
// Draws the current canvas to the screen
void screenDraw() {
  if (screenConfig.canvas == NULL) {
    return;
  }

  int canvasWidth = screenConfig.canvas->size.width;
  int canvasHeight = screenConfig.canvas->size.height;

  clear();

  for (int x = 0; x < screenConfig.canvas->objectCount; x++) {
    Object *obj = screenConfig.canvas->objects[x];

    int i = 0;
    while (obj->content[i] != NULL) {
      char *content = obj->content[i];
      size_t len = strlen(content);

      int posY = obj->position.y + i;
      // Truncate object in case its position makes it go outside of canvas
      if (posY < 0 || posY >= canvasHeight) {
        i++;
        continue;
      }

      int posX = obj->position.x;
      // Truncate object content in case it has negative x-position
      if (posX < 0) {
        int rem = -posX;
        if ((size_t)rem < len) {
          content = &content[rem];
          len -= rem;
        } else {
          content = "";
          len = 0;
        }
        posX = 0;
      }

      // Truncate right part of string in case it exceeds canvas width
      if (posX + len > canvasWidth) {
        // Make sure length does not go negative
        len = (int)fmax(canvasWidth - posX, 0);
      }

      // Check if there is something to draw
      if (len > 0) {
        mvprintw(posY, posX, "%.*s", (int)len, content);
      }

      i++;
    }
  }

  refresh();
}

// The main loop which keeps the screen refreshing
void screenLoop(void (*callback)()) {
  while (running) {
    callback();
    screenDraw();

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

void ScreenSetCanvas(Canvas *canvas) { screenConfig.canvas = canvas; }

void ScreenSetFps(unsigned int fps) {
  screenConfig.fps = fps;
  redrawInterval = 1000000 / fps;
}

TerResult ScreenBeep() {
  if (beep() == ERR) {
    return TerErr;
  }

  return TerOk;
}

void ScreenExit() {
  running = false;
  endwin();
}
