template <typename X>
class Base {
public:
    int basefield;
    using T = int;
};

template <typename T>
class DD : public Base<T> {
public:
    // void f() { basefield = 0; }//
};

template <>
class Base<bool> {
public:
    enum { basefield = 42 }; // tricky
};

void g(DD<bool>& d) { //
    // d.f();// not work
}

// worked examples

template <typename T>
class DD1 : public Base<T> {
public:
    void f() {
        this->basefield = 0; // lookup delayed
    }
};

// or
template <typename T>
class DD2 : public Base<T> {
public:
    void f() {
        Base<T>::basefield = 0; // use qualified name
    }
};

// or
template <typename T>
class DD3 : public Base<T> {
public:
    using Base<T>::basefield;

    void f() {
        basefield = 0; //
    }
};
