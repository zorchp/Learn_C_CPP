#include <iostream>
#include <map>
#include <string>

/// UnsharedConcreteFlyweight（非共享具体享元类）：Coordinates
class Coordinates {
public:
    Coordinates(int x, int y) {
        this->x = x;
        this->y = y;
        std::cout << "Coordinates Hello, x = " << x << " y = " << y
                  << std::endl;
    }
    ~Coordinates() {
        std::cout << "Coordinates Bye, x = " << x << " y = " << y << std::endl;
    }
    int getX() { return x; }
    void setX(int x) { this->x = x; }
    int getY() { return y; }
    void setY(int y) { this->y = y; }

private:
    int x;
    int y;
};

/// Flyweight（抽象享元类）：ChessPiece
class ChessPiece {
public:
    virtual ~ChessPiece() = default;
    virtual std::string getColor() = 0;
    void display(Coordinates *coord) {
        std::cout << "棋子颜色：" << getColor() << "，棋子位置："
                  << "x = " << coord->getX() << "，y = " << coord->getY()
                  << std::endl;
    };

protected:
    ChessPiece() = default;
    std::string color;
};


/// ConcreteFlyweight（具体享元类）：BlackChessPiece  WhiteChessPiece
class BlackChessPiece : public ChessPiece {
public:
    BlackChessPiece() {
        std::cout << "BlackChessPiece Hello" << std::endl;
        color = "黑色";
    }
    ~BlackChessPiece() override {
        std::cout << "BlackChessPiece Bye" << std::endl;
    }
    std::string getColor() override { return color; }
};

class WhiteChessPiece : public ChessPiece {
public:
    WhiteChessPiece() {
        std::cout << "WhiteChessPiece Hello" << std::endl;
        color = "白色";
    }
    ~WhiteChessPiece() override {
        std::cout << "WhiteChessPiece Bye" << std::endl;
    }
    std::string getColor() override { return color; }
};

/// FlyweightFactory（享元工厂类）：ChessPieceFactory
class ChessPieceFactory {
public:
    static ChessPieceFactory *getInstance() {
        static ChessPieceFactory instance;
        return &instance;
    }
    ChessPiece *getChessPiece(const std::string &color) {
        return mapChessPiece[color];
    }

private:
    ChessPieceFactory() {
        std::cout << "ChessPieceFactory Hello" << std::endl;
        mapChessPiece.insert(
            std::pair<std::string, ChessPiece *>("b", new BlackChessPiece()));
        mapChessPiece.insert(
            std::pair<std::string, ChessPiece *>("w", new WhiteChessPiece()));
    }
    ~ChessPieceFactory() {
        std::cout << "ChessPieceFactory Bye" << std::endl;
        auto iter = mapChessPiece.begin();
        while (iter != mapChessPiece.end()) {
            ChessPiece *chessPiece = iter->second;
            delete chessPiece;
            iter++;
        }
    }

    std::map<std::string, ChessPiece *> mapChessPiece;
};

int main() {
    ChessPiece *black1, *black2, *black3, *white1, *white2;
    ChessPieceFactory *factory;

    // 获取享元工厂对象
    factory = ChessPieceFactory::getInstance();

    // 通过享元工厂获取三颗黑子
    black1 = factory->getChessPiece("b");
    black2 = factory->getChessPiece("b");
    black3 = factory->getChessPiece("b");
    std::cout << "两颗黑子是否相同：" << (black1 == black2) << std::endl;

    // 通过享元工厂获取两颗白子
    white1 = factory->getChessPiece("w");
    white2 = factory->getChessPiece("w");
    std::cout << "两颗白子是否相同：" << (white1 == white2) << std::endl;

    std::vector<Coordinates *> coordinates;
    // std::function<Coordinates *(Coordinates *)> func =
    // [&coordinates](Coordinates *coord ) {
    auto func = [&coordinates](Coordinates *coord) {
        coordinates.push_back(coord);
        return coord;
    };
    // 显示棋子
    black1->display(func(new Coordinates(1, 3)));
    black2->display(func(new Coordinates(2, 6)));
    ;
    black3->display(func(new Coordinates(4, 7)));
    ;
    white1->display(func(new Coordinates(5, 8)));
    ;
    white2->display(func(new Coordinates(4, 1)));
    ;

    for (auto &coordinate : coordinates) {
        delete coordinate;
    }
    return 0;
}
