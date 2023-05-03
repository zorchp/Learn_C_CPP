#include <functional>
#include <iostream>
#include <map>

using namespace std;

int add(int a, int b) { return a + b; }

class divide {
public:
    int operator()(int a, int b);
};

int divide::operator()(int a, int b) { return a / b; }

void t1() {
    using fi = function<int(int, int)>;
    fi f1 = add;
    fi f2 = divide();
    fi f3 = [](int i, int j) { return i * j; };
    cout << f1(4, 12) << endl;
    cout << f2(4, 12) << endl;
    cout << f3(4, 12) << endl;
    cout << divide().operator()(1, 2) << endl;
    auto mod = [](int a, int b) { return a % b; };
    map<string, fi> binops = {{"+", add},
                              {"-", minus<int>()},
                              {"/", divide()},
                              {"*", [](int i, int j) { return i * j; }},
                              {"%", mod}};
    cout << binops["-"](10, 5) << endl;
    cout << binops["+"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}