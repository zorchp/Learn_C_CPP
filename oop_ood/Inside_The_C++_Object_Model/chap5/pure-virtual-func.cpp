#include <iostream>
class Abstract_base {
public:
    virtual ~Abstract_base() = 0; // 不要纯虚析构:
                                  // 因为这样就必须类外定义基类的纯虚析构
    virtual void interface() const = 0; // 虚函数不要加 const 声明,
                                        // 因为派生类不一定需要 const
    virtual const char* mumble() const {
        return _mumble;
    } // 不要设计成虚函数, 因为后续的派生类不会改写这个函数

protected:
    Abstract_base(char* pc = "temp") : _mumble(pc) {} // 非要初始化就这样做
    char* _mumble; // 抽象基类最好不要放数据成员:
                   // 否则派生类的基类对象无法决定初值
};

Abstract_base::~Abstract_base() { std::cout << __func__ << std::endl; }

class Concrete_derived : public Abstract_base {
public:
    Concrete_derived() {}
    ~Concrete_derived() { std::cout << __func__ << std::endl; }
    virtual void interface() const;
};


inline void Abstract_base::interface() const {
    std::cout << _mumble << std::endl;
    std::cout << __func__ << std::endl;
}

inline void Concrete_derived::interface() const {
    Abstract_base::interface(); // 纯虚函数被静态调用了
    std::cout << __func__ << std::endl;
}

void t1() {
    //
    Concrete_derived c;
    c.interface();
}
int main(int argc, char* argv[]) {
    t1();
    return 0;
}
