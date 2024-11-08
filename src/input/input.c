#include "input.h"
#include <ncurses.h>

bool IsPressed(int key) { return pressed() == key; }

int Pressed() { return getch(); }
