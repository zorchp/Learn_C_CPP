#include <stdio.h>
void f();
int x;
int main() {
  x = 15213;
  f();
  printf("x=%d\n", x);
  //x=15212
  return 0;
}
