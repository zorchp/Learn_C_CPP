#include <stdio.h>

int main(int argc, char const *argv[]) {
    printf("main: %p\n", *main); // main: 0x1048b7f58
    // void f() {}                  // gcc ok, clang error
    return 0;
}
