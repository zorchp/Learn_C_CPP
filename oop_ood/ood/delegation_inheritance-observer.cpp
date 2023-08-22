#include <bits/stdc++.h>

using namespace std;

/*观察者模式:通过委托+继承完成*/
/*储存数据+表现数据*/

class Subject;

class Observer {
public:
    // 更新, 用来刷新(某一间隔)数据存储方的数据变动
    virtual void update(Subject* sub, int val) = 0; // pure-virtual-func
};


class Subject {
    // 存放数据
private:
    int m_val;
    vector<Observer*> m_views; // delegation
public:
    Subject(int val) : m_val(val) {}
    int get_val() { // 取值
        return m_val;
    }
    void attach(Observer* obs) { // 放数据
        m_views.push_back(obs);
    }
    void notify() { // 通知, 数据发生变动
        for (int i = 0; i < m_views.size(); ++i)
            m_views[i]->update(this, m_val);
    }
    void set_val(int val) { // 设置
        m_val = val;
        notify();
    }
};

class Obs1 : public Observer {
public:
    void update(Subject* sub, int val) {
        cout << "Obs1, now val=" << val << endl;
    }

private:
    int m_val;
};

class Obs2 : public Observer {
public:
    void update(Subject* sub, int val) {
        // sub->set_val(val);
        cout << "Obs2, now val=" << val << endl;
    }

private:
    int m_val;
};

void t1() {
    // 用Observer派生出任意多的子类用于观察
    Obs1* o1 = new Obs1;
    Obs2* o2 = new Obs2;
    Subject* s1 = new Subject(100); // 存数据,修改数据
    s1->attach(o1);
    s1->attach(o2);
    cout << "val=" << s1->get_val() << endl;
    s1->set_val(200);
    cout << "val=" << s1->get_val() << endl;
    s1->set_val(300);
    cout << "val=" << s1->get_val() << endl;
    /*
    val=100
    Obs1, now val=200
    Obs2, now val=200
    val=200
    Obs1, now val=300
    Obs2, now val=300
    val=300
    */
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}