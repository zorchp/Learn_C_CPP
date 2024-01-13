
template <typename X>
class Base {
public:
    int basefield;
    using T = int;
};

class D1 : public Base<Base<void>> {
public:
    void f() { basefield = 3; }
};

template <typename T>
class D2 : public Base<double> {
public:
    void f() { basefield = 7; }

    T strange; // which type?
};

using type = int*;

void g(D2<type>& d2, type p) { //
    // d2.strange = p;
    // Incompatible pointer to integer conversion assigning to 'T' (aka 'int')
    // from 'int *';
}
