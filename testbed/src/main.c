#include <core/logger.h>
#include <core/asserts.h>
#include <platform/platform.h>
#include <stdio.h>
//#include "../../engine/src/core/logger.h"
int main(int argc, char **argv) {
  KFATAL("A test message; %f", 3.14f);
  KERROR("A test message; %f", 3.14f);
  KWARN("A test message; %f", 3.14f);
  KINFO("A test message; %f", 3.14f);
  KDEBUG("A test message; %f", 3.14f);
  KTRACE("A test message; %f", 3.14f);
  platform_state state;
  b8 t = platform_startup(&state, "KABEIROI engine ", 100, 100, 1280, 720);
  KINFO("%d\n", t);
  if (t) {
    while (TRUE) {
      b8 quit = platform_pump_messages(&state);
      if (quit) {
        break;
      }
    }
    platform_shutdown(&state);
  }

  return 0;
}