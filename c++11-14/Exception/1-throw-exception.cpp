#include <iostream>
#include <typeinfo>

using namespace std;


void t1() {
    cout << 0 << endl; //执行
    throw;             // terminate called without an active exception
    cout << 1 << endl; //不执行
}

void t2() {
    try {
        range_error r("error"); // St11range_error
        // out_of_range r("error"); // St12out_of_range
        cout << typeid(r).name() << endl;
        throw r;

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n'; // error
    }
    cout << 2 << endl; //执行
}

void t3() {
    try {
        range_error r("error");
        exception* p = &r;
        cout << typeid(p).name() << endl; // PSt9exception
        throw *p;
        // throw p; // terminate called after throwing an instance of
        //          // 'std::exception*'
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n'; // std::exception
    }
    cout << 2 << endl; //执行
}

void t4() { // rethrow by using `throw;` in `catch`.
    try {
        range_error r("error");
        throw r;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        throw;
    } catch (...) { cout << "1" << '\n'; }
    /*
    error
terminate called after throwing an instance of 'std::range_error'
  what():  error
*/
}

class P {
public:
    P(int a) try : age(a) {
    } catch (...) {
        // std::cerr << e.what() << endl; //
    }

private:
    int age;
};

void t5() { P p(1); }

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();
    return 0;
}
