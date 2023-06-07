#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
    char buf[] = "GET /index.html HTTP/1.1";
    char *idx = strpbrk(buf, " \t");
    printf("%s\n", idx);
    printf("%s\n", buf);
    *idx++ = 0;
    printf("%s\n", idx);
    printf("%s\n", buf);

    //  /index.html HTTP/1.1
    // GET /index.html HTTP/1.1
    // /index.html HTTP/1.1
    // GET
    return 0;
}
