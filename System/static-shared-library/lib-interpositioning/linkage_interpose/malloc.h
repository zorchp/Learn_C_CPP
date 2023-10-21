#include <stddef.h> // size_t

#define malloc(size) __wrap_malloc(size)
#define free(ptr) __wrap_free(ptr)

void* __wrap_malloc(size_t size);
void __wrap_free(void* ptr);
