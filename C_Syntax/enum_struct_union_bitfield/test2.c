#include <stdio.h>
typedef struct classP {
    int age;
    char* name;
} P;

// 通过指针重新分配(实例化)结构体
P* ptr = &(struct classP){
    .age  = 12,
    .name = "Tom",
};

int main(int argc, char const* argv[]) {
    P p1;
    p1.age = 100;
    printf("%d\n", p1.age);
    printf("%d\n", (*ptr).age);
    printf("%d\n", ptr->age);
    printf("%s\n", (*ptr).name);
    printf("%s\n", ptr->name);
    return 0;
    /*
    100
    12
    12
    Tom
    Tom*/
}