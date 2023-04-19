#include <array>
#include <deque>
#include <forward_list>
#include <iostream> // std::cout
#include <iterator> // std::iterator_traits
#include <list>
#include <map>
#include <cxxabi.h>
#include <set>
#include <typeinfo> // typeid
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const char* TypeToName(const char* name) {
    const char* __name = abi::__cxa_demangle(name, nullptr, nullptr, nullptr);
    return __name;
}

void _display_category(random_access_iterator_tag) {
    cout << "random_access_iterator" << endl;
}
void _display_category(bidirectional_iterator_tag) {
    cout << "bidirectional_iterator" << endl;
}
void _display_category(forward_iterator_tag) {
    cout << "forward_iterator" << endl;
}
void _display_category(output_iterator_tag) {
    cout << "output_iterator" << endl;
}
void _display_category(input_iterator_tag) { cout << "input_iterator" << endl; }

template <typename I>
void display_category(I itr) {
    typename iterator_traits<I>::iterator_category cagy;
    _display_category(cagy);

    cout << "typeid(itr).name()= " << typeid(itr).name() << " "
         << TypeToName(typeid(itr).name()) << endl
         << endl;
    // The output depends on library implementation.
    // The particular representation pointed by the
    // returned valueis implementation-defined,
    // and may or may not be different for different types.
}

void test_iterator_category() {
    cout << "\ntest_iterator_category().......... \n";

    display_category(array<int, 10>::iterator());
    display_category(vector<int>::iterator());
    display_category(list<int>::iterator());
    display_category(forward_list<int>::iterator());
    display_category(deque<int>::iterator());

    display_category(set<int>::iterator());
    display_category(map<int, int>::iterator());
    display_category(multiset<int>::iterator());
    display_category(multimap<int, int>::iterator());
    display_category(unordered_set<int>::iterator());
    display_category(unordered_map<int, int>::iterator());
    display_category(unordered_multiset<int>::iterator());
    display_category(unordered_multimap<int, int>::iterator());

    display_category(istream_iterator<int>());
    display_category(ostream_iterator<int>(cout, ""));
}

/*
test_iterator_category()..........
random_access_iterator
typeid(itr).name()= Pi

random_access_iterator
typeid(itr).name()= N9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEE

bidirectional_iterator
typeid(itr).name()= St14_List_iteratorIiE

forward_iterator
typeid(itr).name()= St18_Fwd_list_iteratorIiE

random_access_iterator
typeid(itr).name()= St15_Deque_iteratorIiRiPiE

bidirectional_iterator
typeid(itr).name()= St23_Rb_tree_const_iteratorIiE

bidirectional_iterator
typeid(itr).name()= St17_Rb_tree_iteratorISt4pairIKiiEE

bidirectional_iterator
typeid(itr).name()= St23_Rb_tree_const_iteratorIiE

bidirectional_iterator
typeid(itr).name()= St17_Rb_tree_iteratorISt4pairIKiiEE

forward_iterator
typeid(itr).name()= NSt8__detail14_Node_iteratorIiLb1ELb0EEE

forward_iterator
typeid(itr).name()= NSt8__detail14_Node_iteratorISt4pairIKiiELb0ELb0EEE

forward_iterator
typeid(itr).name()= NSt8__detail14_Node_iteratorIiLb1ELb0EEE

forward_iterator
typeid(itr).name()= NSt8__detail14_Node_iteratorISt4pairIKiiELb0ELb0EEE

input_iterator
typeid(itr).name()= St16istream_iteratorIicSt11char_traitsIcElE

output_iterator
typeid(itr).name()= St16ostream_iteratorIicSt11char_traitsIcEE
*/

// with cxxabi:
/*
test_iterator_category()..........
random_access_iterator
typeid(itr).name()= int*

random_access_iterator
typeid(itr).name()= __gnu_cxx::__normal_iterator<int*, std::vector<int,
std::allocator<int> > >

bidirectional_iterator
typeid(itr).name()= std::_List_iterator<int>

forward_iterator
typeid(itr).name()= std::_Fwd_list_iterator<int>

random_access_iterator
typeid(itr).name()= std::_Deque_iterator<int, int&, int*>

bidirectional_iterator
typeid(itr).name()= std::_Rb_tree_const_iterator<int>

bidirectional_iterator
typeid(itr).name()= std::_Rb_tree_iterator<std::pair<int const, int> >

bidirectional_iterator
typeid(itr).name()= std::_Rb_tree_const_iterator<int>

bidirectional_iterator
typeid(itr).name()= std::_Rb_tree_iterator<std::pair<int const, int> >

forward_iterator
typeid(itr).name()= std::__detail::_Node_iterator<int, true, false>

forward_iterator
typeid(itr).name()= std::__detail::_Node_iterator<std::pair<int const, int>,
false, false>

forward_iterator
typeid(itr).name()= std::__detail::_Node_iterator<int, true, false>

forward_iterator
typeid(itr).name()= std::__detail::_Node_iterator<std::pair<int const, int>,
false, false>

input_iterator
typeid(itr).name()= std::istream_iterator<int, char, std::char_traits<char>,
long>

output_iterator
typeid(itr).name()= std::ostream_iterator<int, char, std::char_traits<char> >
*/

int main(int argc, char const* argv[]) {
    test_iterator_category();
    return 0;
}