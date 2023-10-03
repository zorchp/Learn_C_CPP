#include <iostream>
using namespace std;

// 参考自 C++20高级编程-罗能

struct ForTest {
    int x;
    int y;
    double z;
};

ForTest ft;
ForTest* pFt = &ft;
const ForTest* cpFt = &ft;
ForTest& lr = ft;
ForTest&& rrFt = {};

namespace for_compile {
template <typename, typename...>
struct [[deprecated]] dump;
}

void t1() {
    using namespace for_compile;
    using T1 [[maybe_unused]] = decltype((ft));
    using T2 [[maybe_unused]] = decltype((pFt));
    using T3 [[maybe_unused]] = decltype((cpFt));

    // 编译期知晓类型
    // dump<T1>{};
    // dump<T2>{};
    // dump<T3>{};
}

namespace for_runtime {
template <typename... Ts>
void dump() {
#ifdef _WIN32
    std::cout << __FUNCSIG__ << std::endl;
#else
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}
} // namespace for_runtime

void t2() {
    using namespace for_runtime;
    dump<decltype(ft), decltype((ft)), decltype(pFt), decltype((pFt))>();
}

int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
