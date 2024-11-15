#include "elements/canvas.h"
#include "elements/object.h"
#include "input/input.h"
#include "screen/screen.h"
#include "types.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

Canvas canvas = CANVAS(20, 10);

Object obj = OBJECT(POSITION(6, 3),
                    CONTENT("  /\\",   //
                            "< -- >"), //
                    COLOR(255, 0, 0));

void gameLoop() {
  int input = Pressed();

  switch (input) {
  case 'q':
    ScreenExit();
    break;
  case 'b':
    ScreenBeep();
    break;
  case KEY_UP:
    obj.position.y -= 1;
    break;
  case KEY_LEFT:
    obj.position.x -= 2;
    break;
  case KEY_DOWN:
    obj.position.y += 1;
    break;
  case KEY_RIGHT:
    obj.position.x += 2;
    break;
  }
}

int main() {
  if (CanvasAddObject(&canvas, &obj) == TerErr) {
    fprintf(stderr, "Failed adding object to canvas");
    abort();
  }

  ScreenSetFps(60);
  ScreenSetCanvas(&canvas);

  ScreenRun(gameLoop);

  return 0;
}
