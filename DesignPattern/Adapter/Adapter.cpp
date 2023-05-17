#include <cstdio>
#include <iostream>

using namespace std;

class ThreePhaseOutlet {
public:
    void doThreePhasePlug() { //
        cout << "三相插头接入\n";
    }
};

class TwoPhaseOutlet {
public:
    virtual void doPlug() = 0;
};

// 类适配器, 类的所有对象都被转换
class OutletConverter : public TwoPhaseOutlet, public ThreePhaseOutlet {
public:
    void doPlug() {
        doConvertor();
        doThreePhasePlug();
    }
    void doConvertor() { //
        cout << "三相转为两相\n";
    }
};

void t1() {
    TwoPhaseOutlet* pOutlet = new OutletConverter;
    pOutlet->doPlug();
    // 三相转为两相
    // 三相插头接入
}


// 对象适配器, 更加灵活
class OutletObjConvertor : public TwoPhaseOutlet {
public:
    OutletObjConvertor(ThreePhaseOutlet* pOut) : m_pOut(pOut) {}
    void doPlug() { //
        doConvertor();
        m_pOut->doThreePhasePlug();
    }

    void doConvertor() { cout << " 转换 2->2\n"; }

private:
    ThreePhaseOutlet* m_pOut;
};

void t2() {
    // 此时传入对象指针
    TwoPhaseOutlet* pOutlet = new OutletObjConvertor(new ThreePhaseOutlet);
    pOutlet->doPlug();
    //  转换 2->2
    // 三相插头接入
}

int main(int argc, char* argv[]) {
    //
    // t1();
    t2();
    return 0;
}
