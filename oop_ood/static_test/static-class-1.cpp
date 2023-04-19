#include <iostream>
using namespace std;
class P {
public:
    P() = default;
    ~P() = default;
    /* static void f()const{} */
    static void g() {
        /* this->MAX_age = 1; */
        cout << "g()\n";
    }
    static void h();

    static const int MAX_age = 1;
    static constexpr int MAX_length = 10;
    /* int arr[MAX_length]; */
    int arr[P::MAX_length];
    /* static int MAX_account = 1; */
    static int MAX_account;
};
constexpr int P::MAX_length;
const int *p = &P::MAX_length;
void test(const int &a) { cout << a << endl; }
void t2() {
    /* test(P::MAX_length); */
    cout << P::MAX_length << endl; // 10
}
int P::MAX_account = 10;
/* static void P::h() { cout << "h()\n"; } */
void P::h() { cout << "h()\n"; }

void t1() {
    int b = P::MAX_age;
    cout << b << endl;
    P::MAX_account = 12;
    cout << P::MAX_account << endl; // 12
}

int main(int argc, char *argv[]) {
    /* t1(); */
    t2();
    return 0;
}
