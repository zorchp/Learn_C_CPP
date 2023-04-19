#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void) {
    // buffer to hold the temporary file name
    char nameBuff[32];
    // buffer to hold data to be written/read to/from temporary file
    char buffer[24];
    int filedes = -1, count = 0;

    // memset the buffers to 0
    memset(nameBuff, 0, sizeof(nameBuff));
    memset(buffer, 0, sizeof(buffer));

    // Copy the relevant information in the buffers
    strncpy(nameBuff, "/tmp/myTmpFile-XXXXXX", 21);
    strncpy(buffer, "Hello World", 11);

    errno = 0;
    // Create the temporary file, this function will replace the 'X's
    filedes = mkstemp(nameBuff);

    // Call unlink so that whenever the file is closed or the program exits
    // the temporary file is deleted
    unlink(nameBuff);

    if (filedes < 1) {
        printf("\n Creation of temp file failed with error [%s]\n",
               strerror(errno));
        return 1;
    } else {
        printf("\n Temporary file [%s] created\n", nameBuff);
    }
}
