#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    if (!fork()) {
        while (1) {
            printf("A");
            // sleep(1);
        }
    }
    if (!fork()) {
        while (1) {
            printf("B");
            // sleep(1);
        }
    }
    return 0;
}