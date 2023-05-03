#include <iostream>
#include <string>

using namespace std;

// 构造一个类模板
template <class T1, class T2>
class Person {
public:
    T1 M_name;
    T2 M_age;

    // 构造函数的参数列表写法
    Person(T1 name, T2 age);

    // : M_name(name), M_age(age)
    // {
    //     // this指针的写法
    //     this->M_name = name;
    //     this->M_age = age;
    // }
    // // 实现一个打印信息的成员函数
    void showPerson();
    // {
    //     cout<<"name: "<<this->M_name<<" age: "<<this->M_age<<endl;
    // }
};

// 构造函数的参数列表写法
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
// : M_name(name), M_age(age)
{
    // this指针的写法
    this->M_name = name;
    this->M_age  = age;
}

// 实现一个打印信息的成员函数(类外实现)
template <class T1, class T2>
void Person<T1, T2>::showPerson() {
    cout << "name: " << this->M_name << " age: " << this->M_age << endl;
}

void test1() {
    // 类模板的实例化
    Person<string, int> p("aa", 12);
    cout << p.M_name << " " << p.M_age << endl;
}

void printPerson1(Person<string, int> &p) { p.showPerson(); }

template <class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
    p.showPerson();
}

template <class T>
void printPerson3(T &p) {
    p.showPerson();
}

void test2() {
    // 类模板对象作函数参数
    // 1. 指定传入参数的类型
    Person<string, int> p("aaa", 100);
    printPerson1(p);
    // 2. 参数模板化
    printPerson2(p);
    // 3. 整个类模板化
    printPerson3(p);
}

int main(int argc, char const *argv[]) {
    // test1();
    test2();
    return 0;
}