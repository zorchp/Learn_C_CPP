#include <stdio.h>
void f();
int y = 15212;
int x = 15213;
int main() {
  f();
  printf("x = 0x%x y = 0x%x\n", x, y);
  // x = 0x0 y = 0x3b6c
  return 0;
}
