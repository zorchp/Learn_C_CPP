#include <iostream> // std::cout
#include <iterator> // std::front_inserter
#include <list>     // std::list
// #include <algorithm>    // std::copy
#include <vector>


using namespace std;

// 传入容器:
template <typename C>
void printc(C &v) {
    for (typename C::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void t1() {
    // 基础的copy用法,
    // 需要考虑新加进去元素赋值后会不会对现有内存空间中的元素造成影响
    int myint[]{10, 20, 30, 40, 50, 60, 70};
    vector<int> myvec(7);
    copy(myint, myint + 7, myvec.begin());
    printc(myvec);
}

void t2() {
    list<int> foo, bar;
    for (int i = 1; i <= 5; i++) {
        foo.push_back(i);
        bar.push_back(i * 10);
    }
    cout << "foo: " << endl;
    printc(foo);
    cout << "bar: " << endl;
    printc(bar);
    std::list<int>::iterator it = foo.begin();
    advance(it, 3);

    std::copy(bar.begin(), bar.end(), std::inserter(foo, it));

    std::cout << "foo contains:" << endl;
    printc(foo);
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}