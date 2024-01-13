#include <iostream>
#include <ostream>

class P {
    int age_;

public:
    int get_age() const {
        std::cout << "get...\n";
        return age_;
    }

    void set_age(int age) {
        std::cout << "set...\n";
        age_ = age;
    }

    __declspec(property(get = get_age, put = set_age)) int age;
};

int main(int argc, char *argv[]) {
    P p;
    std::cout << p.age << std::endl;
    p.age = 12;
    std::cout << p.age << std::endl;
    return 0;
}
/*
 ==> g++ -fdeclspec oop_ood/oop/property-non-standard.cpp
  √  ~/code/c-cpp_proj/Learn_C_Cpp
 ==> ./a.out
get...
840171521
set...
get...
12
*/
