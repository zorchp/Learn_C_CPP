#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    void *libHandle;
    void (*funcp)(void);
    const char *err;
    libHandle = dlopen(argv[1], RTLD_LAZY);
    if (!libHandle) fprintf(stderr, "dlopen: %s\n", dlerror());

    // clear dlerror
    (void)dlerror();
    /* *(void **)(&funcp) = dlsym(libHandle, argv[2]); */
    /* funcp = dlsym(libHandle, argv[2]); */
    funcp = (void (*)(void))dlsym(libHandle, argv[2]);
    err = dlerror();
    if (err != NULL) fprintf(stderr, "dlsym: %s\n", err);

    if (!funcp)
        printf("%s is NULL\n", argv[2]);
    else
        // exec it
        (*funcp)();
    dlclose(libHandle);
    exit(EXIT_SUCCESS);

    return 0;
}
