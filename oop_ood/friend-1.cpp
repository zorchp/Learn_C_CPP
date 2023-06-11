struct X {
    friend void f();
    friend void f() {}
    // X() { f(); } // f 还未被声明
    void g();
    void h();
};

// void X::g() { return f(); }
void f();
void X::h() { return f(); }
