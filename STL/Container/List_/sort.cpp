#include <algorithm>
#include <iostream>
#include <list>

int main(int argc, char *argv[]) {
    std::list<int> l{1, 2, 6, 1, 2, 4, 6, 5};
    std::cout << *l.begin() << std::endl;
    // std::cout << *(l.begin() + 2) << std::endl;
    l.sort();
    for (auto x : l) {
        std::cout << x << " ";
    }
    return 0;
}
