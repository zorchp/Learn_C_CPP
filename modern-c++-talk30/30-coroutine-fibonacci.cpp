#include <ranges>
#include <iostream>
using namespace std;

class fibonacci {
public:
    class sentinel;
    class iterator;
    iterator begin() noexcept;
    sentinel end() noexcept;
};

class fibonacci::sentinel {};

class fibonacci::iterator {
public:
    typedef ptrdiff_t difference_type;
    typedef uint64_t value_type;
    typedef const uint64_t* pointer;
    typedef const uint64_t& reference;
    typedef std::input_iterator_tag iterator_category;

    value_type operator*() const { return b_; }
    pointer operator->() const { return &b_; }
    iterator operator++() {
        auto tmp = a_;
        a_ = b_;
        b_ += tmp;
        return *this;
    }
    iterator operator++(int) {
        auto tmp = *this;
        ++*this;
        return tmp;
    }
    bool operator==(const sentinel&) const { return false; }
    bool operator!=(const sentinel&) const { return true; }

private:
    uint64_t a_{0};
    uint64_t b_{1};
};

bool operator==(const fibonacci::sentinel& lhs,
                const fibonacci::iterator& rhs) {
    return rhs == lhs;
}
bool operator!=(const fibonacci::sentinel& lhs,
                const fibonacci::iterator& rhs) {
    return rhs != lhs;
}

inline fibonacci::iterator fibonacci::begin() noexcept { return iterator(); }

inline fibonacci::sentinel fibonacci::end() noexcept { return sentinel(); }

void t1() {
    for (auto i : fibonacci() | views::take(20)) {
        cout << i << endl;
    }
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
