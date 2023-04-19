#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* f1 = tmpfile(); // delete filename when create it
    if (f1 == NULL) fprintf(stderr, "tmpfile");

    const char s[30] = {"hello tmpfile"};
    fputs(s, f1);
    fseek(f1, 0, 0); // 回到文件开头

    char ans[20];
    fgets(ans, 20, f1);
    printf("%s\n", ans); // hello tmpfile

    fclose(f1);
    return 0;
}
