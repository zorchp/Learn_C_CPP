#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct apple {
    int weight;
    int color;
};

struct apple *get_apple_info() {
    struct apple *a1;
    a1 = malloc(sizeof(struct apple));
    if (a1 == NULL) {
        printf("malloc error.\n");
        // return;
    }

    a1->weight = 2;
    a1->color  = 1;

    return a1;
}

int main(int argc, char *argv[]) {
    typeof(get_apple_info())
        r1; //定义一个变量r1,用于接收函数get_apple_info()返回的值，由于该函数返回的类型是：struct
            //apple *，所以变量r1也是该类型。注意，函数不会执行。

    r1 = get_apple_info();

    printf("apple weight:%d\n", r1->weight);
    printf("apple color:%d\n", r1->color);

    return 0;
}
