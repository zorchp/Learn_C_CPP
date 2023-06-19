#include <iostream>
class P {
public:
    P() { std::cout << __func__ << std::endl; }
    ~P() { std::cout << __func__ << std::endl; }
    void f() { std::cout << __func__ << std::endl; }
    virtual void g() { std::cout << __func__ << std::endl; }
    void h() {
        std::cout << val << std::endl;
        std::cout << __func__ << std::endl;
    }
    int val;
};

int main(int argc, char *argv[]) {
    P *p{};
    p->f(); // function static bind
    // p->g(); // SEGV
    // p->h(); // SEGV
    return 0;
}
