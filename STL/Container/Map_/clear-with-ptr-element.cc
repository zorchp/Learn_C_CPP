#include <iostream>
#include <map>
#include <utility>

struct A {
    ~A() { x = 0; }

    int x;
};

int main(void) {
    std::map<int, A *> my_map;
    A *a = new A();
    a->x = 5;
    // my_map.insert(std::pair{0, a});
    my_map.insert(std::pair<int, A *>(0, a));
    // my_map.emplace(0, a);
    // my_map.insert(std::make_pair(0, a));

    // addresses will be the same, will print 5
    std::cout << a << " " << my_map[0] << " " << my_map[0]->x << std::endl;

    // 除非显式调用 delete
    // delete my_map[0];

    // 均不会调用析构函数.
    // my_map.clear();
    my_map.erase(0);

    // will be 0
    std::cout << a->x << std::endl;

    return 0;
}
