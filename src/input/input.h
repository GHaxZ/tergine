#ifndef INPUT_H
#define INPUT_H
#include <stdbool.h>

// Whether specified key code is pressed
bool IsPressed(int key);

// The currently pressed key code, -1 if none is pressed
int Pressed();

#endif // !INPUT_H
