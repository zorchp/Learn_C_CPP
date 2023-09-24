#include <cstddef>
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    cout << nullptr << endl; // nullptr
    printf("treat nullptr as int : %d\n", nullptr);

    nullptr_t nu = NULL;
    //
    printf("%d\n", nullptr == NULL);
    printf("%d\n", nullptr == 0);
    // who cast to who? TODO
    printf("%d\n", (void *)nullptr == NULL);
    printf("%d\n", nullptr == (std::nullptr_t)NULL);
    return 0;
}
