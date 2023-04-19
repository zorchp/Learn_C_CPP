#include <bits/stdc++.h>

using namespace std;

/*复合模式, 用于实现目录, 可以放目录或者文件*/

class Component {
public:
    Component(int val) : m_val(val) {}
    virtual void add(Component*) {
    } //不能是pure-virtual, 因为primitive不一定有add()
private:
    int m_val;
};


class Primitive : public Component {
public:
    Primitive(int val) : Component(val) {}
};

class Composite : public Component {
public:
    Composite(int val) : Component(val) {}
    void add(Component* elem) { c.push_back(elem); }

private:
    std::vector<Component*> c;
};

void t1() {}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}