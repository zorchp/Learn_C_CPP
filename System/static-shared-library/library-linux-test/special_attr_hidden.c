#include <stdio.h>

void __attribute__((visibility("hidden"))) t1(void) { printf("unreachable\n"); }

/* void t1(void) { printf("unreachable\n"); } */

/* int main(int argc, char *argv[]) { */
/*     t1(); */
/*     return 0; */
/* } */
