#include <iostream>
using namespace std;
/* 在初始化列表中调用“基准版本”的构造函数为委派构造函数（delegating
 * constructor），而被调用的“基准版本”则为目标构造函数（target constructor） */

class Info {
public:
    Info() { InitRest(); } // 目标ctor
    /* Info(int i) : Info(), type(i) {} */
    // error: an initializer for a delegating constructor must appear alone
    Info(int i) : Info() { type = i; }  // delegating ctor
    Info(char e) : Info() { name = e; } // delegating ctor
    void print() { cout << type << " " << name << endl; }

private:
    void InitRest() {
        type += 1;
        cout << "call InitRest()\n";
    }
    int type{1};
    char name{'a'};
    // ...
};
int main(int argc, char *argv[]) {
    Info i1;
    i1.print();
    /* call InitRest() */
    /* 1 a */
    Info i2(3); // 在InitRest()中变成4之后,在委派构造中又被赋值为3,
                // 这也能说明目标构造先于委派构造执行
    i2.print();
    /* call InitRest() */
    /* 3 a */
    return 0;
}
