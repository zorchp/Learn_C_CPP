#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    system("ls | wc");
     /* 13      13     170 */
    return 0;
}
