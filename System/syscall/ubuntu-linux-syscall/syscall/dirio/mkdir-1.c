#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

// rw-r--r--
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
// rwxrwxr-x
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IWGRP | S_IXGRP | S_IXOTH)

int main(int argc, char *argv[]) {
    mkdir("aa", DIR_MODE);
    return 0;
}
