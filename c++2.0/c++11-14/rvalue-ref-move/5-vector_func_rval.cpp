#include <iostream>
#include <vector>

using namespace std;

void printv(const vector<int>& v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
}
vector<int> process_copy(std::vector<int> const& vec_) {
    //可接受rval或lval, 但都会强制进行复制
    std::vector<int> vec(vec_);
    cout << "origin func can process rval and lval, but it must use copy"
         << endl;
    vec.push_back(42);
    return vec;
}
void t1() {
    vector<int> v1{};
    printv(v1);
    process_copy(v1);
    printv(v1);
}

// //重载版本,对右值进行操作
// vector<int> process_copy(std::vector<int>&& vec) {
//     cout << "using overload func, only process rval" << endl;
//     vec.push_back(42);
//     return vec;
// }

void t2() {
    printv({1, 2});
    printv(process_copy({1, 2}));
    /*with overload func
    1 2
    using overload func, only process rval
    1 2 42
    */
    /*if not overload func:
    1 2
    origin func can process rval and lval, but it must use copy
    1 2 42
    */
}
int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}