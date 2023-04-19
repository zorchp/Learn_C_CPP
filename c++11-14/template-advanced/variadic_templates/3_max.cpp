#include <iostream>

using namespace std;

template <class ForwardIterator, class Compare>
ForwardIterator __max_elem(ForwardIterator first, ForwardIterator last,
                           Compare comp) {
    if (first == last) return first;
    ForwardIterator result = first;
    while (++first != last)
        if (comp(result, first)) // result<first
            result = first;
    return result;
}


struct Iter {
    //仿函数
    template <typename I1, typename I2>
    bool operator()(I1 it1, I2 it2) const {
        return *it1 < *it2;
    }
};


inline Iter __iter_less_iter() { return Iter(); }


template <class T>
inline T max_elem(T first, T last) {
    return __max_elem(first, last, __iter_less_iter());
}


template <typename T>
inline T max1(initializer_list<T> l) {
    return *max_elem(l.begin(), l.end());
}


int main(int argc, char const *argv[]) {
    cout << max1({1, 2, 333, 45}) << endl;
    cout << max1({("Fff"), ("Eoa"), ("Acc")})
         << endl; //此时是在通过 array进行比较
    cout << max({string("Fff"), string("Eoa"), string("Acc")}) << endl;
    cout << max({'a', 'c', 'b'}) << endl;
    cout << max({"a", "c", "b"}) << endl;
    return 0;
}