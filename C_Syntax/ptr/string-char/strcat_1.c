#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const* argv[]) {
    char* error        = "ERROR: ";
    char* errorMessage = "Not enough memory";
    char* buffer = (char*)malloc(strlen(error) + strlen(errorMessage) + 1);
    strcpy(buffer, error);
    char* tmp = strcat(buffer, errorMessage);
    printf("%s\n", tmp);
    printf("%s\n", buffer);
    printf("%s\n", error);
    printf("%s\n", errorMessage);
    /*
    ERROR: Not enough memory
    ERROR: Not enough memory
    ERROR:
    Not enough memory
    */
    return 0;
}