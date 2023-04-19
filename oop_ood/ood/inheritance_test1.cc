#include <iostream>

using namespace std;

/*
采用虚函数的继承关系的类设计

*/

class CDocument {
public:
    void OnFileOpen() {
        cout << "dialog..." << endl;
        cout << "check file ..." << endl;
        cout << "open file ..." << endl;
        Serialize();
        cout << "close file .." << endl;
        cout << "update all views ..." << endl;
    }

    virtual void Serialize() const = 0;
};

class CMyDoc : public CDocument {
public:
    virtual void Serialize() const {
        cout << "只有应用程序才知道如何读取这个文件" << endl;
        cout << "CMyDoc::Serialize()" << endl;
    }
};

int main(int argc, char const *argv[]) {
    CMyDoc myDoc;
    myDoc.OnFileOpen();
    /*

    dialog...
    check file ...
    open file ...
    只有应用程序才知道如何读取这个文件
    CMyDoc::Serialize()
    close file ..
    update all views ...
    */
    return 0;
}