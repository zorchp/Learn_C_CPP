#include <iostream>
using namespace std;

void test1() {
    [] { cout << "hello lambda" << endl; }();
    auto l1 = [](int a, int b) { return a < b ? a : b; };
    auto l2 = [] { cout << "this is l2" << endl; };
    // auto l3 = [] (auto a, auto && b) { return a < b; }; //
    // 仅能在C++14及以后使用

    cout << l1(12, 93) << endl;
    l2();
    // cout << l3(3, 3.14) << endl;
}

void test2() {
    int id1 = 0, i2 = 2, i3 = 3;
    auto f1 = [=, &id1]() mutable {
        cout << "id1: " << id1 << endl;
        cout << "i2: " << i2 << endl;
        cout << "i3: " << i3 << endl;
        ++id1;
        ++i2;
        ++i3;
    };
    id1 = 42;
    f1();
    f1();
    f1();
    cout << "id1: " << id1 << endl;
    cout << "i2: " << i2 << endl;
    cout << "i3: " << i3 << endl;
}


void t3() {
    int id  = 0;
    auto f2 = [id]() mutable {
        cout << "id: " << id << endl;
        ++id;
    };
    id = 42;
    f2();
    f2();
    f2();
    cout << "id: " << id << endl;
}

class Functor {
private:
    int id1;

public:
    Functor(int t) : id1(t) {}
    void operator()() {
        cout << "id1: " << id1 << endl;
        ++id1;
    }
};

void t4() {
    int id1 = 0;
    Functor f3(id1);
    id1 = 42;
    f3();
    f3();
    f3();
    cout << "id1: " << id1 << endl;
}


int main(int argc, char const *argv[]) {
    // test1();
    // test2();
    t3();
    t4();
    return 0;
}