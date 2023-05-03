#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    system("echo {a,b}{c,{d,e}}");

    return 0;
}
