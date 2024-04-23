#include <coroutine>
#include <iostream>
#include<generator>

class Values {
public:
    generator<int> operator()() {
        co_yield 1;
        co_yield 2;
        co_yield 3;
    }
};

int main (int argc, char *argv[]) {
    Values v;for (auto i: v){
        std::cout<<i<<" ";
    }
    return 0;
}
