#include <iostream>

class B1 {
public:
    B1() {}
    virtual ~B1() {}
    virtual void speak_clearly();
    virtual B1* clone() const;

protected:
    float data_B1;
};
class B2 {
public:
    B2() {}
    virtual ~B2() {}
    virtual void mumble();
    virtual B2* clone() const;

protected:
    float data_B2;
};

class D : public B1, public B2 {
public:
    D() {}
    virtual ~D() {}
    virtual D* clone() const;

protected:
    float data_D;
};

void t1() {
    //
    B2* pB2 = new D;

    // 编译器层面:, 加偏移量以支持多态
    // D* tmp = new D;
    // B2* pB2 = tmp ? tmp + sizeof(B1) : 0;

    // 如果没有这样的调整, 下面会失败:
    // pB2->data_B2;

    delete pB2; // 此时还存在调整, 以指出完整对象的起始点
    // 上面的调整都在 RunTime 完成
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
