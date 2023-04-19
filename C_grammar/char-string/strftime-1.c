#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);

    info = localtime(&rawtime);

    // strftime(buffer, 80, "%x - %I:%M%p", info);
    strftime(buffer, 80, "%A %c", info);
    printf("Formatted date & time : |%s|\n", buffer);

    return (0);
}