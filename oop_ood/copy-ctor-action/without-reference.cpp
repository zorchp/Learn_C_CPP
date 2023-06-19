#include <iostream>
class P {
public:
    P() : val(1) { std::cout << __func__ << '\n'; }
    ~P() { std::cout << __func__ << '\n'; }
    P(P &rhs) {
        val = rhs.val;
        std::cout << "copy " << __func__ << '\n';
    }
    P &operator=(P &rhs) {
        val = rhs.val;
        std::cout << "copy " << __func__ << '\n';
        return *this;
    }
    P(P *rhs) {
        val = rhs->val;
        std::cout << "ptr " << __func__ << '\n';
    }

    int val;
};

void t1() {
    P p, q(p);
    P *pp = new P;
    P r(pp);
    std::cout << r.val << '\n'; // 1
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
