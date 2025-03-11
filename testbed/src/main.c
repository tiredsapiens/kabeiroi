#include <core/logger.h>
#include <core/asserts.h>
#include <stdio.h>
//#include "../../engine/src/core/logger.h"
int main(int argc, char **argv) {
  KFATAL("A test message; %f",3.14f);
  KERROR("A test message; %f",3.14f);
  KWARN("A test message; %f",3.14f);
  KINFO("A test message; %f",3.14f);
  KDEBUG("A test message; %f",3.14f);
  KTRACE("A test message; %f",3.14f);
  KASSERT(1==0)
  return 0;
}