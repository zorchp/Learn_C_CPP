#include <iostream>
#include <string>

template <class T>
void show_type(T t) {
    std::cout << typeid(t).name() << std::endl;
}

template <class T>
// void normal_forwarding(T t) {//效率低下
// void normal_forwarding(T &t) {//右值报错
// void normal_forwarding(const T &t) { //不能改值
void normal_forwarding(T &&t) {
    t = "abc";
    show_type(t);
}
std::string get_string() { return "hi world"; }

void t1() {
    std::string s = "hello world";
    normal_forwarding(s);            //左值
    normal_forwarding(get_string()); //右值
}


/*std::move一定会将实参转换为一个右值引用，并且使用std::move不需要指定模板实参，
 * 模板实参是由函数调用推导出来的。
 * 而std::forward会根据左值和右值的实际情况进行转发，在使用的时候需要指定模板实参。*/

template <class T>
void perfect_forwarding(T &&t) {
    // show_type(static_cast<T &&>(t));
    show_type(std::forward<T>(t));
}

void t2() {
    std::string s = "hello world";
    perfect_forwarding(s);
    perfect_forwarding(get_string());
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    // t3();
    return 0;
}