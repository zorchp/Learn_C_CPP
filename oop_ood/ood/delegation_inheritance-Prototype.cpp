#include <iostream>

using namespace std;

enum imageType { LSAT, SPOT };

class Image {
public:
    virtual void draw() = 0;
    static Image *findAndClone(imageType);

protected:
    virtual imageType returnType() = 0;
    virtual Image *clone()         = 0;
    //每一个子类一旦声明, 就被注册为原型(Prototype)
    static void addPrototype(Image *image) { _prototypes[_nextSlot++] = image; }

private:
    // addPrototype()保存每一个注册的原型
    static Image *_prototypes[10];
    static int _nextSlot;
};
//静态成员类外初始化
Image *Image::_prototypes[];
int Image::_nextSlot;

Image *Image::findAndClone(imageType type) {
    for (int i = 0; i < _nextSlot; ++i)
        if (_prototypes[i]->returnType() == type)
            return _prototypes[i]->clone();
}

//子类
class LandSatImage : public Image {
public:
    imageType returnType() { return LSAT; }
    void draw() { cout << "LandSatImage::draw()" << _id << endl; }
    //当clone()被调用, 调用含有一个dummy参数的构造函数
    Image *clone() {
        return new LandSatImage(
            1); //这里加入参数用于区分构造函数, 放入原型的构造函数只能调用一次,
                //这里通过加上int来区别原型
    }

protected:
    // 该构造函数仅从clone()调用执行一次
    LandSatImage(int dummy) { _id = _count++; }

private:
    static LandSatImage _landSatImage;
    // 仅当私有静态数据成员初始化后调用
    LandSatImage() {
        addPrototype(this); //把自己放入原型(框架端)
    }
    //名义上的状态
    int _id;
    static int _count;
};

//注册子类的原型
LandSatImage LandSatImage::_landSatImage;
//每一次实例化之前, 初始化状态
int LandSatImage::_count = 1;

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}