#include <deque>
#include <string>
#include <vector>
#include <iostream>


namespace base_version {
template <typename T>
class Stack {
    std::deque<T> elems;

public:
    void push(T const& item) { elems.push_back(item); }
    void pop() { elems.pop_back(); }
    T top() const { return elems.back(); }
    bool empty() const { return elems.empty(); }

    // 成员模板
    template <typename T2> // 不同类型的栈拷贝赋值
    Stack<T>& operator=(Stack<T2> const&);
};

template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& rhs) {
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
} // namespace base_version

void t1() {
    using namespace base_version;
    Stack<int> s1, s2;
    Stack<float> f1;
    s1 = s2;
    f1 = s1;
    Stack<std::string> ss;
    // f1 = ss;
}

namespace custom_container {

template <typename T, typename CONT = std::deque<T>>
class Stack {
    CONT elems;

public:
    void push(T const& item) { elems.push_back(item); }
    void pop() { elems.pop_back(); }
    T top() const { return elems.back(); }
    bool empty() const { return elems.empty(); }

    // 成员模板
    template <typename T2, typename CONT2> // 不同类型的栈拷贝赋值
    Stack<T, CONT>& operator=(Stack<T2, CONT2> const&);
};

template <typename T, typename CONT>
template <typename T2, typename CONT2>
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
} // namespace custom_container

void t2() {
    using namespace custom_container;
    Stack<int, std::vector<int>> vs;
    vs.push(42);
    vs.push(43);
    std::cout << vs.top();
}


int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
