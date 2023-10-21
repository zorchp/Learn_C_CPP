#include <bits/stdc++.h>
using namespace std;

class Quad { // 四边形
public:
    Quad() { cout << __PRETTY_FUNCTION__ << endl; }
    virtual ~Quad() { cout << __PRETTY_FUNCTION__ << endl; }
    virtual double calc() {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0.;
    }
};

class Rectangle : public Quad {
    double m_x;
    double m_y;

public:
    Rectangle() { cout << __PRETTY_FUNCTION__ << endl; }
    Rectangle(double x, double y) : m_x(x), m_y(y) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~Rectangle() { cout << __PRETTY_FUNCTION__ << endl; }
    virtual double calc() override {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0.;
    }
};

class Square : public Quad {
    double m_x;

public:
    Square() { cout << __PRETTY_FUNCTION__ << endl; }
    Square(double x) : m_x(x) { cout << __PRETTY_FUNCTION__ << endl; }
    ~Square() { cout << __PRETTY_FUNCTION__ << endl; }
    virtual double calc() {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0.;
    }
};

void t1() {
    // 派生类指针指向基类对象
    // Rectangle *pRect = new Quad;
    // pRect->calc();
    // auto pRect = dynamic_cast<Rectangle *>(new Quad); // runtime error
    auto pRect = static_cast<Rectangle *>(new Quad); // ok
    pRect->calc();
    /*
    Quad::Quad()
    virtual double Quad::calc()
    */
}

void t2() {
    // 运行时多态
    Quad *pQuad = new Rectangle;
    pQuad->calc();
    delete pQuad;
    /*
    Quad::Quad()
    Rectangle::Rectangle()
    virtual double Rectangle::calc()
    virtual Rectangle::~Rectangle()
    virtual Quad::~Quad()
    */
}

void t3() {
    // Square *pSqua = new Rectangle; // 派生自同一基类的派生类
    Square *pSqua = new Square;
    // auto pRect = dynamic_cast<Rectangle *>(pSqua); // runtime error
    // 强制类型转换可以:
    auto pRect = reinterpret_cast<Rectangle *>(pSqua);
    pRect->calc();
    /*
    Quad::Quad()
    Square::Square()
    virtual double Square::calc()
    */
    // 指向父类的转换可以
    auto pQuad = dynamic_cast<Quad *>(pSqua);
    pQuad->calc();
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    // t3();
    return 0;
}
