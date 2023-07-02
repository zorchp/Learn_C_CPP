#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class StrBlobPtr; // friend
class StrBlob {
public:
    friend class StrBlobPtr;
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
    typedef vector<string>::size_type size_type;
    // ctor:
    StrBlob();
    StrBlob(initializer_list<string> il);
    // size,empty
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add,delete elem
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    // get elem
    string &front();
    string &back();
    auto get_data() { return data; }
    // get elem: const(overload)
    const string &front() const;
    const string &back() const;
    ~StrBlob(){};

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const; // 检查data[i]
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) throw out_of_range(msg);
}

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

void t1() {
    StrBlob b1;
    {
        StrBlob b2{"a", "b", "ss"};
        b1 = b2;
        b2.push_back("cc");
        cout << b2.size() << endl; // 4,同一份数据
        cout << b2.get_data() << endl;
    }
    cout << b1.size() << endl; // 4,同一份数据
    cout << b1.get_data() << endl;
    /*4
0x6000009e8040
4
0x6000009e8040*/
}


class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr(); // 前置递增
private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<sting>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const { // 解引用
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //*p就是指向的vector对象
}

StrBlobPtr &StrBlobPtr::incr() { // 前置自增
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


void t2() {}
int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}