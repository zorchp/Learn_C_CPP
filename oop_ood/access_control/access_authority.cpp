#include <iostream>

using namespace std;

class Person {
public:
    // 公共权限
    string myName;

    void func() {
        myName = "zhangsan";
        myCar = "bentian";
        Password = 465;
    }

protected:
    // 保护权限
    string myCar;

private:
    // 私有权限
    int Password;
};
void t1() {
    Person p;
    p.myName = "lisi";
    // p.myCar = "nnn"; // protected
    // p.Password = 11111; // private
}

class Tom : public Person {
    friend void f(Person& p);
    friend void f(Tom& t);
    int j;
};
// void f(Person& p) { p.myCar = "a"; }
void f(Tom& t) { t.myCar = "b"; } // ok, just access by Derived class object

void t2() {
    Tom t;
    // t.myCar = "22";// protected
}


int main(int argc, char const* argv[]) {
    // t1();
    t2();

    return 0;
}
