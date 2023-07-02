#include <stdio.h>
#include <string.h>

void t1() {
    const char* str = "hello";
    char buf[10];
    memmove(buf, str, 4);
    printf("%s\n", buf);
    printf("%s\n", str);
}

void t2() {
    char str1[] = "Geeks"; // Array of size 100
    char str2[] = "Quiz";  // Array of size 5

    puts("str1 before memmove ");
    puts(str1);

    /* Copies contents of str2 to sr1 */
    memmove(str1, str2, sizeof(str2));

    puts("\nstr1 after memmove ");
    puts(str1);
}
int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}
