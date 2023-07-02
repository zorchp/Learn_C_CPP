struct S {
    inline static int x =
        0; // static data member
           // a definition outside of class is required if it is odr-used
};

const int& f(const int& r) {
    return r;
}
bool b = true;

// int n = b ? (1, S::x) // S::x is not odr-used here
//           : f(S::x);  // S::x is odr-used here: a definition is required

int main(int argc, char* argv[]) {
    // t1();
    f(S::x);
    return 0;
}
