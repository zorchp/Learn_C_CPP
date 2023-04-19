#include <algorithm>
#include <functional> //bind
#include <iostream>
#include <vector>
using namespace std;
using namespace std::placeholders;


double my_div(double x, double y) { return x / y; }

void t1() {
    __bind<double (&)(double, double), int, int> fn_five = bind(my_div, 10, 2);
    cout << fn_five() << endl; // 5
    __bind<double (&)(double, double), const __ph<1> &, int> fn_half =
        bind(my_div, _1, 2);
    cout << fn_half(10) << endl; // 5

    __bind<double (&)(double, double), const __ph<2> &, const __ph<1> &>
        fn_invert = bind(my_div, _2, _1);
    cout << fn_invert(10, 2) << endl; // 0.2

    // specify return-type
    __bind_r<int, double (&)(double, double), const __ph<1> &, const __ph<2> &>
        fn_rounding = bind<int>(my_div, _1, _2);
    cout << fn_rounding(10, 3) << endl; // 3 not 3.3
}

struct MyPair {
    double a, b;
    double multiply() { return a * b; }
    // member function has a argument : this
};

void t2() {
    MyPair ten_two{10, 2};
    __bind<double (MyPair::*)(), const __ph<1> &> bound_mem_fn =
        bind(&MyPair::multiply, _1);
    cout << bound_mem_fn(ten_two) << endl; // 20

    __bind<double MyPair::*, MyPair &> bound_mem_data =
        bind(&MyPair::a, ten_two);
    cout << bound_mem_data() << endl; // 10

    __bind<double MyPair::*, const __ph<1> &> bound_mem_dta_2 =
        bind(&MyPair::b, _1);
    cout << bound_mem_dta_2(ten_two) << endl; // 2
}

void t3() {
    vector<int> v{12, 32, 43, 45, 456};
    // int n=count_if(v.begin(),v.end(),not1(bind2nd(less<int>(), 50)));
    // cout<<"n="<<n<<endl;
    __bind<std::less<int>, const __ph<1> &, int> fn_ =
        bind(less<int>(), _1, 50);
    cout << count_if(v.cbegin(), v.cend(), fn_) << endl; // 4
    cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 50))
         << endl; // 4
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}