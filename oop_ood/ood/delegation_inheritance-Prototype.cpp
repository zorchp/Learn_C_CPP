#include <iostream>
#include <cassert>

using namespace std;


enum imageType { LSAT, SPOT };

class Image {
public:
    virtual void draw() = 0;
    static Image *findAndClone(imageType type) {
        for (int i = 0; i < _nextSlot; ++i)
            if (_prototypes[i]->returnType() == type)
                return _prototypes[i]->clone();
        return nullptr;
    }

protected:
    virtual imageType returnType() = 0;
    virtual Image *clone() = 0;
    // 每一个子类一旦声明, 就被注册为原型(Prototype)
    static void addPrototype(Image *image) {
        cout << "call addPrototype() ";
        _prototypes[_nextSlot++] = image;
    }

private:
    // addPrototype()保存每一个注册的原型
    static Image *_prototypes[10];
    static int _nextSlot;
};
// 静态成员类外初始化
Image *Image::_prototypes[];
int Image::_nextSlot = 0;


// 子类
class LandSatImage : public Image {
public:
    imageType returnType() { return LSAT; }
    void draw() { cout << "LandSatImage::draw(), id=" << _id << endl; }
    // 当clone()被调用, 调用含有一个dummy参数的构造函数
    Image *clone() {
        return new LandSatImage(1);
        // 这里加入参数用于区分构造函数, 放入原型的构造函数只能调用一次,
        // 通过加上int来区别原型
    }

protected:
    // 该构造函数仅从clone()调用执行一次
    LandSatImage(int dummy) { _id = _count++; }

private:
    static LandSatImage _landSatImage;
    // 仅当私有静态数据成员初始化后调用
    LandSatImage() {
        addPrototype(this); // 把自己放入原型(框架端)
        cout << ": " << returnType() << endl; // enum Value
    }
    // 名义上的状态
    int _id;
    static int _count;
};
// 注册子类的原型
LandSatImage LandSatImage::_landSatImage;
// 每一次实例化之前, 初始化状态
int LandSatImage::_count = 1;

class SpotImage : public Image {
public:
    imageType returnType() { return SPOT; }
    void draw() { cout << "SpotImage::draw(), id=" << _id << endl; }
    // 当clone()被调用, 调用含有一个dummy参数的构造函数
    Image *clone() {
        return new SpotImage(1);
        // 这里加入参数用于区分构造函数, 放入原型的构造函数只能调用一次,
        // 通过加上int来区别原型
    }

protected:
    // 该构造函数仅从clone()调用执行一次
    SpotImage(int dummy) { _id = _count++; }

private:
    static SpotImage _spotImage;
    // 仅当私有静态数据成员初始化后调用
    SpotImage() {
        addPrototype(this); // 把自己放入原型(框架端)
        cout << ": " << returnType() << endl; // enum Value
    }
    // 名义上的状态
    int _id;
    static int _count;
};

// 注册子类的原型
SpotImage SpotImage::_spotImage;
// 每一次实例化之前, 初始化状态
int SpotImage::_count = 1;

int main(int argc, char const *argv[]) {
    Image* l1 = Image::findAndClone(LSAT);
    assert(l1 != nullptr);
    Image* l2 = dynamic_cast<LandSatImage*>(l1)->clone(); // 调用子类的 clone 方法
    assert(l2 != nullptr);
    auto l3 = Image::findAndClone(SPOT);
    assert(l3 != nullptr);
    l1->draw();
    l2->draw();
    l3->draw();
    return 0;
}