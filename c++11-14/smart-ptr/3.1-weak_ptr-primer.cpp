#include <iostream>
#include <memory>
#include <vector>

using namespace std;
/*weak_ptr
是一种不控制所指向对象生存期的智能指针, 其指向一个由shared_ptr管理的对象,
将一个weak_ptr绑定到一个shared_ptr上不会改变shared_ptr的引用计数.
主要还是看shared_ptr的引用计数,为0则释放,
而不会因为weak_ptr(指向该对象后)影响引用计数从而影响释放, 如其名'weak_ptr'
*/
void t1() {
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p); // wp弱共享p,p的引用计数不变
    // 或者通过赋值:
    weak_ptr<int> wp1;
    wp1 = p;
    wp1.reset();                                           // 置为nullptr
    cout << "wp1.use_count()=" << wp1.use_count() << endl; // 0
    cout << "wp1.expired()=" << wp1.expired() << endl;     // 1
    cout << "wp1.lock()==nullptr: " << (wp1.lock() == nullptr) << endl; // 1
    cout << p << endl;
    cout << *p << endl;
    // wp指向的对象可能不存在, 所以不能直接取值,
    // 需要采用lock()[lock()返回弱指针指向对象的shared_ptr]
    // cout << *wp << endl; // 弱指针不能直接解引用
    // cout << wp << endl; // 弱指针不能直接输出值(地址)
    cout<<wp.lock()<<endl;
    cout<<*(wp.lock())<<endl;
    if (shared_ptr<int> np = wp.lock())
    {
        cout<<np<<" "<<*np<<endl;
    }//0x600000ff9110 42
}


int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
