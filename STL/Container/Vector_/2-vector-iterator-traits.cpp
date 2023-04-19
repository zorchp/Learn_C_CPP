#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename Container>
void traits_test(Container c) {
    typedef typename iterator_traits<
        typename Container::iterator>::iterator_category Itc;

    typedef typename iterator_traits<typename Container::iterator>::value_type
        Valtype;

    typedef
        typename iterator_traits<typename Container::iterator>::difference_type
            Difftype;
    typedef typename iterator_traits<typename Container::iterator>::pointer Ptr;
    typedef
        typename iterator_traits<typename Container::iterator>::reference Ref;
    Itc a1;
    Valtype a2;
    Difftype a3;
    Ptr a4;
    int a  = 2;
    Ref a5 = a;
    cout << typeid(a1).name() << endl;
    cout << typeid(a2).name() << endl;
    cout << typeid(a3).name() << endl;
    cout << typeid(a4).name() << endl;
    cout << typeid(a5).name() << endl;
    // cout << typeid(int).name() << endl;//i:int
    // cout << typeid(long).name() << endl;//l:long
    cout << typeid(int *).name() << endl; // Pi:int*
    cout << typeid(int &).name() << endl; // i:int
    /*
    St26random_access_iterator_tag
    i
    l
    Pi
    i
    */
}
void t1() {
    vector<int> vec{1, 2};
    vector<int>::iterator ite = vec.begin();
    traits_test(vector<int>());
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
