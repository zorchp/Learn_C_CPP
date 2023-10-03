#include <iostream>
#include <ranges>
using namespace std;


template <ranges::input_range R>
auto sum(R&& r) {
    ranges::range_value_t<R> value{};
    for (auto e : r) {
        value += e;
    }
    return value;
}
int main(int argc, char* argv[]) {
    using namespace std::views;
    auto res = iota(1) | transform([](auto n) { return n * n; }) |
               filter([](auto n) { return n % 2 == 1; }) |
               take_while([](auto n) { return n < 10000; });
    cout << sum(res) << endl;
    return 0;
}
