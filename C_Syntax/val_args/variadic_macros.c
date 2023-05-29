#include <stdarg.h>
#include <stdio.h>

#define f(...) printf(__VA_ARGS__)


int main(void) {

    f("%s, %s", "s", "ci");
    return 0;
}
