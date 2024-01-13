#include <stdio.h>

int main() {
    printf("stdin=%p\n", stdin);
    printf("stdin _file=%d\n", stdin->_file);
    printf("stdout=%p\n", stdout);
    printf("stdout _file=%d\n", stdout->_file);
    printf("stderr=%p\n", stderr);
    printf("stderr _file=%d\n", stderr->_file);

    FILE* fp = fopen("aa.txt", "wb");
    if (fp == NULL) return -1;
    printf("fp=%p\n", fp);
    printf("fp file=%d\n", fp->_file);
    fwrite("abcde", 5, 1, fp);
    fclose(fp);

    printf("fp=%p\n", fp);
    printf("fp file=%d\n", fp->_file);

    fp = fopen("bb.txt", "wb");
    if (fp == NULL) return -1;
    printf("fp=%p\n", fp);
    printf("fp file=%d\n", fp->_file);

    fwrite("fghij", 5, 1, fp);
    fclose(fp);

    printf("fp=%p\n", fp);
    printf("fp file=%d\n", fp->_file);

    int i;
    FILE* f[60];
    char buf[20];
    for (i = 0; i < 60; ++i) {
        snprintf(buf, 10, "%d.txt", i);
        f[i] = fopen(buf, "wb");
        printf("f[i] file=%d\n", f[i]->_file);
    }

    return 0;
}
