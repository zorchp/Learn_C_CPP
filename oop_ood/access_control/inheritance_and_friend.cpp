class Base {
    friend class Pal;

protected:
    int prot_mem;
};

class Sneaky : public Base {
    friend void f(Sneaky&);
    friend void f(Base&);
    int g() { return prot_mem; }
    // int h() {
    //     Base b;
    //     return b.prot_mem; // 不能通过基类对象来获取其 protected 成员
    // }
    int j; // private
};

void t1() {
    Base b;
    // b.prot_mem;
}

void f(Sneaky& s) { s.j = s.prot_mem = 0; }
// void f(Base& b) { b.prot_mem = 0; } // protected

class Pal {
public:
    int f1(Base b) { return b.prot_mem; } // ok, Pal is a friend of Base
    // int f2(Sneaky s) { return s.j; } // private
    // 友元可以访问保护和私有的, 此时 Base 是 Sneaky 中的一部分
    int f3(Sneaky s) { return s.prot_mem; } // ok, Pal is a friend of Base
};

class D2 : public Pal {
public:
    // int mem(Base b) { return b.prot_mem; } // 友元关系不能继承
    // 每个类都负责控制各自成员的访问权限
};
