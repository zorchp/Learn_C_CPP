#include <cassert>
#include <iostream>

class Rectangle {
public:
    virtual ~Rectangle() = default;

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    virtual void setWidth(int w) { width = w; }

    virtual void setHeight(int h) { height = h; }

    virtual int getArea() const { return getHeight() * getWidth(); }

protected:
    int width;
    int height;
};

class Square : public Rectangle {
public:
    Square(int x) { setWidth(x); }

    void setWidth(int w) override {
        width = w;
        height = w;
    }

    void setHeight(int h) override {
        width = h;
        height = h;
    }

    int getArea() const override { return width * width; }
};

void transform(Rectangle& rect) {
    rect.setHeight(4);
    rect.setWidth(7);
    std::cout << rect.getArea() << std::endl;
    assert(rect.getArea() == 28);
}

void t1() {
    Square s{3};
    transform(s);
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
