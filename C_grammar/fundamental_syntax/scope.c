#include <stdio.h>

void fun() {
    int a = 3, b;
    printf("fun()函数里面的a值为：%d\n", a);

    return;
}

int main(void) {
    int a = 0, b;
    {
        int a = 1;
        printf("main()函数里面被大括号封装的a值为：%d\n", a);
    }
    fun();
    printf("main()函数里面的a值为：%d\n", a);
    /*main()函数里面被大括号封装的a值为：1
    fun()函数里面的a值为：3
    main()函数里面的a值为：0
    */
    return 0;
}