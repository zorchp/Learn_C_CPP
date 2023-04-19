#include <ostream>
#include <string>
#include <iostream>
using namespace std;

class ZooAnimal {
public:
    ZooAnimal() { cout << "call ZooAnimal::ZooAnimal()\n"; }
    void print() { cout << "call ZooAnimal::print()\n"; }
    ~ZooAnimal() { cout << "call ZooAnimal::~ZooAnimal()\n"; }
};

class Endangered {
public:
    Endangered() { cout << "call Endangered::Endangered()\n"; }
    Endangered(int a) : m_a(a) { cout << "call Endangered::Endangered(int)\n"; }
    ~Endangered() { cout << "call Endangered::~Endangered()\n"; }

    static int critical;

private:
    int m_a;
};
int Endangered::critical = 10;

class Bear : public ZooAnimal {
public:
    Bear() { cout << "call Bear::Bear()\n"; }
    Bear(string, bool, string);
    ~Bear() { cout << "call Bear::~Bear()\n"; }
};
Bear::Bear(string name, bool onExhibit, string detail) {
    cout << "call Bear::Bear(string, bool, string)\n";
}

// multi inherit
class Panda : public Bear, public Endangered {
public:
    Panda();
    Panda(string, bool);
    ~Panda() { cout << "call Panda::~Panda()\n"; }
};

Panda::Panda(string name, bool onExhibit)
    : Bear(name, onExhibit, "Panda"), Endangered(Endangered::critical) {
    cout << "call Panda::Panda(string, bool)\n";
}
Panda::Panda() : Endangered(Endangered::critical) {
    cout << "call Panda::Panda()\n";
}

void t1() {
    //
    Panda p1;
    /* call ZooAnimal::ZooAnimal() */
    /* call Bear::Bear() */
    /* call Endangered::Endangered(int) */
    /* call Panda::Panda() */
    /* call Panda::~Panda() */
    /* call Endangered::~Endangered() */
    /* call Bear::~Bear() */
    /* call ZooAnimal::~ZooAnimal() */
}

void print(const Bear &) { cout << "call print(const Bear&)\n"; }
void highlight(const Endangered &) {
    cout << "call highlight(const Endangered&)\n";
}
ostream &operator<<(ostream &os, const ZooAnimal &) {
    os << "call operator<< (ZooAnimal)\n";
    return os;
}
// 如果解注释, 会导致错误
/* error: call of overloaded 'print(Panda&)' is ambiguous */
/* void print(const Endangered &) { cout << "call print(const Endangered&)\n"; }
 */
void t2() {
    Panda aa("aa", true);
    print(aa);
    highlight(aa);
    cout << aa << endl;
    /* call print(const Bear&) */
    /* call highlight(const Endangered&) */
    /* call operator<< (ZooAnimal) */
}

void t3() {
    Bear *pb = new Panda("aa", true);
    pb->print();
    delete pb;
    /* call ZooAnimal::ZooAnimal() */
    /* call Bear::Bear(string, bool, string) */
    /* call Endangered::Endangered(int) */
    /* call Panda::Panda(string, bool) */
    /* call ZooAnimal::print() */
    /* call Bear::~Bear() */
    /* call ZooAnimal::~ZooAnimal() */
}

int main(int argc, char *argv[]) {
    /* t1(); */
    /* t2(); */
    t3();
    return 0;
}
