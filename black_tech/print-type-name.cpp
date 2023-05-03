#include <typeinfo>

template <typename...>
struct type_name {};
template <typename... Ts>
struct name_of {
    using X = typename type_name<Ts...>::name;
};
class P {};
int main() {
    name_of<P>(); //
}