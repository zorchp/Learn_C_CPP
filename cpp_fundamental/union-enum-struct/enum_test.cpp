#include <iostream>
#include <typeinfo>

using namespace std;

void test1() {
    enum { n = 10 };
    printf("%d\n", n);
    // 对enum定义的值取地址非法
    // printf("%d\n", &n);
}

void test2() {
    enum week { sun = 7, mon = 1, tue, wed, thu, fri, sat };
    week tmp;
    cout << tmp << endl;
}

void test3() {
    // 枚举类型用于提高代码可读性
    enum week {
        Mon = 1,
        Tues,
        Wed,
        Thurs,
        Fri,
        Sat,
        Sun
    } a = Mon,
      b = Wed, c = Sat;
    week w1 = Mon, abb = Sat;
    cout << typeid(w1).name() << endl;
    cout << w1 << endl;
    cout << typeid(abb).name() << endl;
    cout << abb << endl;
    cout << typeid(Sun).name() << endl;
    cout << typeid(a).name() << endl;
    cout << typeid(week).name() << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

int main(int argc, char const* argv[]) {
    // test1();
    // test2();
    test3();
    return 0;
}