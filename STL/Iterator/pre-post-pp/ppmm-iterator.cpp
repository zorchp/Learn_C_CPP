#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
    vector<int> v{1, 2, 3};
    auto it = v.begin();
    // cout << *(++it) << endl;
    cout << *(it++) << endl;
    return 0;
}
/* clang llvm
_LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX14 __wrap_iter& operator++()
    _NOEXCEPT {
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__dereferenceable(this),
                         "Attempted to increment a non-incrementable iterator");
    ++__i_;
    return *this;
}
_LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX14 __wrap_iter
operator++(int) _NOEXCEPT {
    __wrap_iter __tmp(*this);
    ++(*this);
    return __tmp;
} */
