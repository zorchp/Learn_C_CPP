#include <complex>
#include <iostream>
#include <string>
#include <tuple>


using namespace std;

void t1() {
    cout << "sizeof(int)=" << sizeof(int) << endl;
    cout << "sizeof(float)=" << sizeof(float) << endl;
    cout << "sizeof(double)=" << sizeof(double) << endl;
    cout << "sizeof(string)=" << sizeof(string) << endl;
    tuple<int, float, string, complex<double>> t;
    cout << "sizeof(t)=" << sizeof(t) << endl;
    /*
    sizeof(int)=4
sizeof(float)=4
sizeof(double)=8
sizeof(string)=24
sizeof(t)=48
*/
}

void t2() {
    tuple<int, float, string> t1{1, 2.3, "hello"};
    cout << "sizeof(tuple<int, float, string> t1)=" << sizeof(t1) << endl;
    /*sizeof(tuple<int, float, string> t1)=32*/
    cout << "t1: " << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1)
         << endl; // t1: 1 2.3 hello

    // tuple<int, double, const char *> t2 = make_tuple(22, 1, "aa");
    tuple<int, double, string> t2 = make_tuple(22, 1, "aa");
    cout << "t2: " << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2)
         << endl;
    // clang++:
    /*    tuple<int, double, typename __unwrap_ref_decay<string>::type> t2 =
            make_tuple(22, 44.3, "ss"s);
    */
    // g++:
    /*    tuple<int, double,
              std::__cxx11::basic_string<char, std::char_traits<char>,
                                         std::allocator<char>>>
            t2 = make_tuple(22, 44.3, "ss"s);
    */
    get<1>(t1) = get<1>(t2);
    cout << "get<1>(t1) = get<1>(t2)" << endl;
    cout << "t1: " << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1)
         << endl;
    cout << "(t1 < t2): " << (t1 < t2) << endl; // 1, 只比较第一个值
}

void t3() {
    tuple<int, float, string> t3{1, 2.3, "hello"};
    int i1;
    float f1;
    string s1;
    tie(i1, f1, s1) = t3; // unpack
    cout << "t3: " << get<0>(t3) << " " << get<1>(t3) << " " << get<2>(t3)
         << endl;
    cout << "(i1, f1, s1)=" << i1 << ", " << f1 << ", " << s1 << endl;
    typedef tuple<int, float, string> TupleType;
    cout << tuple_size<TupleType>::value << endl; // 3
    tuple_element<1, TupleType>::type f11 = 1.0;  // float
    typedef tuple_element<1, TupleType>::type mytype;
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
