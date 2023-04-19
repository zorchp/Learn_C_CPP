#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

const int MAX_ALLOCS = 1000000;

const int NUM = 1000;
const int BLOCK_SIZE = 10240;
const int FREE_STEP = 1;

const int FREE_MIN = 1;
const int FREE_MAX = NUM;

int main(int argc, char *argv[]) {
    char *ptr[MAX_ALLOCS];
    int j;

    if (NUM > MAX_ALLOCS) fprintf(stderr, "num-allocs > %d\n", MAX_ALLOCS);
    if (FREE_MAX > NUM) fprintf(stderr, "free-max > num-allocs\n"), exit(1);

    printf("Initial program break:          %10p\n", sbrk(0));

    printf("Allocating %d*%d bytes\n", NUM, BLOCK_SIZE);
    for (j = 0; j < NUM; j++) {
        ptr[j] = malloc(BLOCK_SIZE);
        if (ptr[j] == NULL) fprintf(stderr, "malloc");
    }

    printf("Program break is now:           %10p\n", sbrk(0));

    printf("Freeing blocks from %d to %d in steps of %d\n", FREE_MIN, FREE_MAX,
           FREE_STEP);
    for (j = FREE_MIN - 1; j < FREE_MAX; j += FREE_STEP) free(ptr[j]);

    printf("After free(), program break is: %10p\n", sbrk(0));

    exit(EXIT_SUCCESS);
}

/* Initial program break:            0x645000 */
/* Allocating 1000*10240 bytes */
/* Program break is now:            0x102e000 */
/* Freeing blocks from 1 to 1000 in steps of 1 */
/* After free(), program break is:   0x666000 */

/* Initial program break:           0x10b0000 */
/* Allocating 1000*10240 bytes */
/* Program break is now:            0x1a99000 */
/* Freeing blocks from 1 to 1000 in steps of 2 */
/* After free(), program break is:  0x1a99000 */

/* Initial program break:            0xf52000 */
/* Allocating 1000*10240 bytes */
/* Program break is now:            0x193b000 */
/* Freeing blocks from 1 to 999 in steps of 1 */
/* After free(), program break is:  0x193b000 */

/* Initial program break:           0x222f000 */
/* Allocating 1000*10240 bytes */
/* Program break is now:            0x2c18000 */
/* Freeing blocks from 500 to 1000 in steps of 1 */
/* After free(), program break is:  0x2731000 */
