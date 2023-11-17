#include <iostream>

void t1() {
    auto p = new int;
    delete p;
    p = nullptr;
    delete p;
    delete p;
    delete p;
}

void t2() {
    auto p = malloc(4);
    free(p);
    p = NULL;
    free(p);
    free(p);
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
