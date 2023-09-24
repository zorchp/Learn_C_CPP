#include <bits/stdc++.h>
using namespace std;

namespace StaticPoly {
class Line {
public:
    void Draw() const { std::cout << "Line Draw()\n"; }
};

class Circle {
public:
    void Draw(const char* name = NULL) const { std::cout << "Circle Draw()\n"; }
};

class Rectangle {
public:
    void Draw(int i = 0) const { std::cout << "Rectangle Draw()\n"; }
};

template <typename Geometry>
void DrawGeometry(const Geometry& geo) {
    geo.Draw();
}

template <typename Geometry>
void DrawGeometry(std::vector<Geometry> vecGeo) {
    const size_t size = vecGeo.size();
    for (size_t i = 0; i < size; ++i) vecGeo[i].Draw();
}
} // namespace StaticPoly

void t1() {
    StaticPoly::Line line;
    StaticPoly::Circle circle;
    StaticPoly::Rectangle rect;
    StaticPoly::DrawGeometry(circle);
    StaticPoly::DrawGeometry(line);
    StaticPoly::DrawGeometry(rect);
    return;

    std::vector<StaticPoly::Line> vecLines;
    StaticPoly::Line line2;
    StaticPoly::Line line3;
    vecLines.push_back(line);
    vecLines.push_back(line2);
    vecLines.push_back(line3);
    // vecLines.push_back(&circle); //编译错误，已不再能够处理异质对象
    // vecLines.push_back(&rect);    //编译错误，已不再能够处理异质对象
    StaticPoly::DrawGeometry(vecLines);

    std::vector<StaticPoly::Circle> vecCircles;
    vecCircles.push_back(circle);
    StaticPoly::DrawGeometry(circle);
}

void t2() {
    //
}


int main() {
    t1();
    return 0;
}
