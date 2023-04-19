#include <stdio.h>
#include <stdlib.h>


// typedef struct ff {
//   int a;
//   int b;
// } foo1;
// int bar(int a, int b) {
//   return a+b;
// }

struct foo {
    int (*bar)(struct foo *this, int a, int b); // 函数指针
};

int bar1(struct foo *this, int a, int b) { return a + b; }


struct foo *get_object() {
    struct foo *this;
    return this;
}


void baz() {
    struct foo s    = {.bar = bar1};
    struct foo *ptr = &s;
    printf("ptr: %p\n", ptr);
    int ret = ptr->bar(ptr, 3, 4);
    printf("%d\n", ret);
    // 等效于C++: ptr->bar(3, 4)
}


int main(int argc, char const *argv[]) {
    baz();
    return 0;
}