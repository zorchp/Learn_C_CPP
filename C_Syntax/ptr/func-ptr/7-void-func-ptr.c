#include <stdio.h>
typedef void (*fptrBase)();
typedef int (*fptrToSingleInt)(int);
typedef int (*fptrToTwoInts)(int, int);
int add(int a, int b) { return a + b; }
int main() {
    fptrBase basePointer;
    fptrToTwoInts fptrFirst = add;

    basePointer = (fptrToSingleInt)fptrFirst;
    fptrFirst   = (fptrToTwoInts)basePointer;
    printf("%d\n", fptrFirst(5, 6)); // 11
    /*
    7-void-func-ptr.c: In function 'main':
    7-void-func-ptr.c:11:17: warning: assignment to 'fptrBase' {aka 'void
    (*)()'} from incompatible pointer type 'int (*)(int)'
    [-Wincompatible-pointer-types] 11 |     basePointer =
    (fptrToSingleInt)fptrFirst; |                 ^ [Finished in 624ms]
    */
}