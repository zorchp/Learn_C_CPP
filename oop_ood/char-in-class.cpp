#include <iostream>
class P {
public:
    char a;
};
int main(int argc, char *argv[]) {
    P p;
    p.a = 1;
    std::cout << sizeof(P); // 1
    std::cout << sizeof(p); // 1
    return 0;
}
