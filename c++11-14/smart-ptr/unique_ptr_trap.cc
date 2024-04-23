#include <iostream>
#include <memory>

auto foo(std::unique_ptr<int> ptr) {
    *ptr = 42;
    return ptr;
}

int main(int argc, char *argv[]) {
    auto ptr = std::make_unique<int>();
    // ptr = foo(std::move(ptr));
    ptr = foo(ptr);// copy-ctor =delete
    std::cout << *ptr << std::endl;
    return 0;
}
