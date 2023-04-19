#include <iostream>
using namespace std;
class Info {
public:
    Info() : Info(1, 'a') {}
    Info(int i) : Info(i, 'a') {}
    Info(char e) : Info(1, e) {}
    void print() { cout << type << " " << name << endl; }

private:
    // 私有目标构造函数, 可以不需要InitRest()
    Info(int i, char e) : type(i), name(e) {
        /* type += 1; */
        cout << "target ctor..\n";
    }
    int type;
    char name;
    // ...
};
void t1() {
    Info i1;
    i1.print();
    Info i2(2);
    i2.print();
    Info i3('x');
    i3.print();
    /* target ctor.. */
    /* 1 a */
    /* target ctor.. */
    /* 2 a */
    /* target ctor.. */
    /* 1 x */
    // 在C++11中，目标构造函数的执行总是先于委派构造函数
    //  if add `type+=1`:
    /* target ctor.. */
    /* 2 a */
    /* target ctor.. */
    /* 3 a */
    /* target ctor.. */
    /* 2 x */
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
