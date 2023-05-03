#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
    const char* str = "hello";
    char buf[10];
    memmove(buf, str, 6);
    // memmove(
    //     str, buf,
    //     6); // note: expected 'void *' but argument is of type 'const char *'
    printf("%s\n", buf);
    return 0;
}
