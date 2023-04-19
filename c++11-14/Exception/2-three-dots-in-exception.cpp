#include <functional>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class my_exception : public std::runtime_error {
public:
    using this_type = my_exception;
    using super_type = std::runtime_error;

public:
    my_exception(const char* msg) : super_type(msg) {}
    /* my_exception() = default; */
    ~my_exception() = default;

private:
    int code = 0;
};

[[noreturn]] void raise(const char* msg) { throw my_exception(msg); }

void t1() {
    try {
        int* p = 0;
        if (!p) throw(1);
        cout << p << endl;

    } catch (...) { cout << "error\n"; }
    cout << "other code ...\n";
}

void t2() try { raise("error occuerd"); } catch (const exception& e) {
    cout << e.what() << endl;
}

void func_noexcept() noexcept {
    cout << "noexcept\n";
    throw(1);
}


int main(int argc, char const* argv[]) {
    /* t1(); */
    /* t2(); */
    func_noexcept();
    return 0;
}
