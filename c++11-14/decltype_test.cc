#include <bits/stdc++.h>

using namespace std;

int f() { return 1; }

void t1() {
    // decltype类型指示符(declare type: 声明类型)
    // decltype(f()) 相当于 int
    decltype(f()) sum = 10;
    cout << sum << endl;
}

void t2() {
    const int ci = 0, &cj = ci;
    decltype(ci) x = 10; // 此时x为const int类型
    // const int x=10;
    decltype(cj) y = x; // y为const int类型
    // const int &y=10;
    // y=10;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}

void t3() {
    int i = 42, *p = &i, &r = i;
    decltype(r + 10) b;
    // 表达式内容为解引用操作:*p,则decltype得到引用类型
    // decltype(*p) 代表的类型为int&
    decltype(*p) c = i;
    // 变量是一种可以作为赋值语句左值的特殊表达式,
    // 于是下面的decltype((i))得到引用类型 int&
    decltype((i)) e = i;
}

void t4() {
    map<string, float> coll;
    decltype(coll)::value_type elem;
    // map<string, float>::value_type elem;
}

// Usage of `decltype`:
// 1. declare return type
// before C++11, we need declare the type of x and y.
// int x, y;// must declare
// template<typename T1, typename T2>
// decltype(x + y) add(T1 x, T2 y);

// with C++11, we don't need declare the type of x1 and y1.
template <typename T1, typename T2>
auto add1(T1 x1, T2 y1) -> decltype(x1 + y1);


// 2.metaprogramming(with template)
template <typename T>
void test_decltype(T obj) {
    map<string, float>::value_type elem1;
    map<string, float> coll;
    decltype(coll)::value_type elem2;


    typedef typename decltype(obj)::iterator iType;
    decltype(obj) anotherObj(obj);
}

void t5() {
    // test_decltype(complex<int>());//error: no type named 'iterator' in
    // 'std::complex<int>'
}

// 3. pass the type of a lambda
class Person {
public:
    Person(const string& s) : lastname(s) {}
    string lastname;
};

auto cmp = [](const Person& p1, const Person& p2) {
    return p1.lastname < p2.lastname;
};

void t6() {
    set<Person, decltype(cmp)> coll(
        cmp); // lambda没有默认构造函数(和赋值操作符), 只能这样写
}
int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    // t5();
    t6();
    return 0;
}