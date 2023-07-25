struct Base {
    virtual void Turing() = 0;
    virtual void Dijkstra() = 0;
    virtual void VNeumann(int g) = 0;
    virtual void DKnuth() const;
    void Print();
};
struct DerivedMid : public Base {
    // void VNeumann(double g);
    // 接口被隔离了，曾想多一个版本的VNeumann函数
};
/* 如果派生类在虚函数声明时使用了override描述符，那么该函数必须重载其基类中的同名函数，否则代码将无法通过编译
 */
struct DerivedTop : public DerivedMid {
    void Turing() override;
    void Dikjstra() override; // 无法通过编译，拼写错误，并非重载
    void VNeumann(double g) override; // 无法通过编译，参数不一致，并非重载
    void DKnuth() override; // 无法通过编译，常量性不一致，并非重载
    void Print() override; // 无法通过编译，非虚函数重载
};
// 编译选项:g++ -c -std=c++11 2-10-3.cpp
