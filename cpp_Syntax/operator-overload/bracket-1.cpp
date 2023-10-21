#include <bits/stdc++.h>
#include <cxxabi.h>
using namespace std;

#if __cplusplus < 202002
#define print_type(x)                                                    \
    std::cout << #x << typeid(x).name() << " => "                        \
              << abi::__cxa_demangle(typeid(x).name(), NULL, NULL, NULL) \
              << std::endl
#else
#define print_type(x)                            \
    std::cout << std::format(                    \
        "{} : {} => {}\n", #x, typeid(x).name(), \
        abi::__cxa_demangle(typeid(x).name(), NULL, NULL, NULL))
#endif

struct myVec {
    int arr[10];
    operator int*() { return arr; } // for `idx[arr]`
    int& operator[](int idx) {
        cout << "call overload func operator[]\n";
        return *(arr + idx);
    }
    void print() const {
        cout << "now arr is: \n";
        for (auto i : arr) {
            cout << i << " ";
        }
        cout << '\n';
    }
};

void t0() {
    myVec v;
    v[0] = 12;
    1 [v] = 13;
    v.print();
    print_type(1 [v]); // int
}


void t1() {
    vector v{1, 2, 3};
    print_type(decltype((v[0])));
    print_type(v[1]);
}

int main(int argc, char* argv[]) {
    // t0();
    t1();

    return 0;
}
