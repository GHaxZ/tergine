#include "input.h"
#include <ncurses.h>

bool IsPressed(int key) { return Pressed() == key; }

int Pressed() { return getch(); }
