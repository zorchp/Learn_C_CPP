#include <iostream>

using namespace std;

/*
构造函数的三种类型:
1. 默认构造函数
2. 有参构造函数
3. 拷贝构造函数

构造函数的调用规则:
1. 编译器会在类生成的时候自动创建以下三个构造函数:
    1. 默认构造函数(空实现:{})
    2. 析构函数(空实现:{})
    3. 拷贝构造函数(值拷贝)

2. 当用户初始化有参构造函数之后, 编译器不再提供默认构造函数,
但是还会提供拷贝构造函数 若用户初始化了拷贝构造函数,
则编译器不再提供其他普通的构造函数
*/
class Person {
public:
    // Person() {
    //     cout<<"默认构造函数调用"<<endl;
    // }
    Person() = default;
    Person(int a) {
        cout << "有参构造函数" << endl;
        mage = a;
    }

    // Person(const Person &p) {
    //     cout<<"拷贝构造函数"<<endl;
    //     mage = p.mage;
    // }
    ~Person() { cout << "析构函数调用_" << endl; }

    int mage;
};


// void test1() {
//     Person p;
//     p.mage = 1;

//     Person p1(p);
//     cout<<"p1年龄:"<<p1.mage<<endl;

// }

void test2() {
    //若用户初始化有参构造函数,编译器不会提供默认构造函数,此时初始化会报错
    Person p;//但是加上=default就不会报错.
    // Person p(29);
    // Person p1(p);
    // cout<<"p1年龄为:"<<p1.mage<<endl;
}

int main(int argc, char const *argv[]) {
    // test1();
    test2();
    return 0;
}