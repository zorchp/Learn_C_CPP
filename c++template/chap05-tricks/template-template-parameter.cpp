#include <deque>
#include <list>
#include <string>
#include <vector>
#include <iostream>

// 函数模板不支持模版模版参数


// old version
// template <typename T, typename CONT = std::deque<T>>
// 模版模版参数
// template <typename T, template <typename ELEM> class CONT = std::deque>
template <typename T,
          template <typename ELEM, typename ALLOC = std::allocator<ELEM>>
          class CONT = std::deque>
class Stack {
    CONT<T> elems;

public:
    void push(T const& item) { elems.push_back(item); }
    void pop() { elems.pop_back(); }
    T top() const { return elems.back(); }
    bool empty() const { return elems.empty(); }

    // 成员模板
    template <typename T2,
              template <typename, typename> class CONT2 = std::deque>
    Stack<T, CONT>& operator=(Stack<T2, CONT2> const&);
};

template <typename T, template <typename, typename> class CONT>
template <typename T2, template <typename, typename> class CONT2>
Stack<T, CONT>& Stack<T, CONT>::operator=(Stack<T2, CONT2> const& rhs) {
    if ((void*)this == (void*)&rhs) {
        return *this;
    }
    auto tmp(rhs);
    elems.clear();
    while (!tmp.empty()) {
        elems.push_front(tmp.top());
        tmp.pop();
    }
    return *this;
}


void t1() {
    // clang error, need `-frelaxed-template-template-args`, gcc ok
    // consider deque default argument..

    Stack<int, std::deque> vs;
    // error: template template argument has different template parameters than
    // its corresponding template template parameter
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
