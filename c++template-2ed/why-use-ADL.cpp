template <typename T>
inline T const &MyMax(T const &a, T const &b) {
    return a < b ? b : a;
}

namespace BigMath {
class BigNumber {
    //
};

bool operator<(BigNumber const &, BigNumber const &);
} // namespace BigMath

using BigMath::BigNumber;

void g(BigNumber const &a, BigNumber const &b) {
    //
    BigNumber x = MyMax(a, b);
}
