#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <dlfcn.h>

void *malloc(size_t size) {
    void *(*mallocp)(size_t size);
    char *error;

    mallocp = dlsym(RTLD_NEXT, "malloc"); // get addr of libc malloc
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    char *ptr = mallocp(size);
    fprintf(stderr, "malloc(%d)=%p\n", (int)size, ptr);
    return ptr;
}

void free(void *ptr) {
    void (*freep)(void *) = NULL;
    char *error;
    if (!ptr) {
        return;
    }
    freep = dlsym(RTLD_NEXT, "free");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    freep(ptr);
    fprintf(stderr, "free(%p)\n", ptr);
}
#endif
