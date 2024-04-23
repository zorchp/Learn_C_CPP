#include <string>
#include <iostream>
#include <variant>

struct Node {
    int val;
    Node* next;
};

namespace union_test {


enum class Type { ptr, num };

union Value { // 减少空间占用
    Node* p;
    int i;
};

struct Entry {
    std::string name;
    Type t;
    Value v;
};
} // namespace union_test

void t1() {
    using namespace union_test;
    Entry p1{"abc", Type::num};

    if (p1.t == Type::num) {
        std::cout << p1.v.i;
    } else {
        ///
    }
}

namespace variant_test {
struct Entry {
    std::string name;
    std::variant<Node*, int> v; // 此时不再需要枚举
};

} // namespace variant_test

void t2() {
    using namespace variant_test;
    Entry p2{"abc", 1};
    if (std::holds_alternative<int>(p2.v)) {
        std::cout << std::get<int>(p2.v);
    }
}

int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
