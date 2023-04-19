#include <iostream>

using namespace std;


class Person {
public:
    Person() { cout << "默认构造函数调用" << endl; };
    Person(int a) {
        cout << "有参构造函数" << endl;
        mage = a;
    }

    Person(const Person& p) {
        cout << "拷贝构造函数" << endl;
        mage = p.mage;
    }
    Person& operator=(const Person&) {
        cout << "copy-assign func call\n";
        return *this;
    }
    ~Person() { cout << "析构函数调用" << endl; }

    int mage;
};

void t1() {
    Person p1;
    Person p2 = p1;
    Person p3(p2);
    Person p4;
    p4 = p1;
    /*
    默认构造函数调用
    拷贝构造函数
    拷贝构造函数
    默认构造函数调用
    copy-assign func call
    析构函数调用
    析构函数调用
    析构函数调用
    析构函数调用
    */
}
int main(int argc, char const* argv[]) {
    t1();
    return 0;
}