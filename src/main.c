#include "screen/screen.h"
int main() {
  ScreenConfig config = {.fps = 60};

  ScreenInit(config);

  return 0;
}
