#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>

void func(void* x) { printf("func\n"); }

int main(int argc, char* argv[]) {
    /* void* y; */
    /* y = alloca(10); */
    /* func(y); */
    func(alloca(10));
    return 0;
}
