
// #include<stdio.h>
// #include <pthread.h>
// #include <time.h>
// #include <unistd.h>
// int turn;
// pthread_t pid1;
// pthread_t pid2;

// _Noreturn void* fun1(void *p) {
// //pthread_join(pid1,NULL);
//     do {
//         while (turn == 2);
//         printf("0\n");
//         printf("i am the process 1\n");
//         printf("1\n");
//         turn = 2;
//         sleep(3);
//     } while (1);
// }

// _Noreturn void* fun2(void *p)
// {
// //pthread_join(pid1,NULL);
// do{
//     while(turn ==1)

//         printf("2\n");
//         printf("i am the process 2\n");
//         printf("3\n");
//         turn=1;
//         sleep(100);
//     }while(1);

// }
// int main(void)
// {

//     turn=1;
//     int a=pthread_create(&pid1,NULL,fun1,NULL);
//     int b=pthread_create(&pid2,NULL,fun2,NULL);

//     pthread_join(pid1,NULL);
//     pthread_join(pid2,NULL);
//     //这里是为了阻塞，可能主线进程直接没了，但是还没轮到pid1,pid2执行
//     printf("4\n");
//     if(a==0&&b==0)
//         printf("success\n");
//     printf("bye\n");
// }

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int turn;
pthread_t pid1;
pthread_t pid2;
int count = 10000;
int a[2];
_Noreturn void* fun1(void* p) {
    // pthread_join(pid1,NULL);
    do {
        while (a[0] == 1)
            ;
        if (turn == 1) {
            a[1] = 1;
            printf("0\n");
            count--;
            printf("i am the process 1  :%d\n", count);
            printf("1\n");
            a[1] = 0;
            turn = 2;
            sleep(3);
        }
    } while (1);
}

_Noreturn void* fun2(void* p) {
    // pthread_join(pid1,NULL);
    do {
        while (a[1] == 1)
            if (turn == 2) {
                a[0] = 1;
                printf("2\n");
                count--;
                printf("i am the process 2  :%d\n", count);
                printf("3\n");
                turn = 1;
                a[0] = 0;
                sleep(3);
            }
    } while (1);
}
int main(void) {
    turn  = 1;
    a[0]  = 0;
    a[1]  = 0;
    int a = pthread_create(&pid1, NULL, fun1, NULL);
    int b = pthread_create(&pid2, NULL, fun2, NULL);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    printf("4\n");
    if (a == 0 && b == 0) printf("success\n");
    printf("bye\n");
}