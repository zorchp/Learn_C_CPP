#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <typeinfo>
using namespace std;


auto make_regex = [](const auto& txt) { return regex(txt); };
auto make_match = []() { return smatch(); };

void t1() {
    auto str = "thisisa:sentence"s;
    auto reg = make_regex(R"(^(\w+)\:(\w+)$)");
    auto what = make_match();
    regex_match(str, what, reg);
    for (auto x : what) cout << x << " ";
    /* thisisa:sentence thisisa sentence  */
}

void t2() {
    auto s1 = "god of war"s;
    auto reg = make_regex(R"((\w+)\s(\w+))");
    auto what = make_match();
    auto found = regex_search(s1, what, reg);
    cout << found << endl;
    cout << !what.empty() << endl;
    cout << what[1] << endl;
    cout << what[2] << endl;
    /*     1 */
    /* 1 */
    /* god */
    /* of */
}

void t3() {
    auto s2 = "hello world"s;
    auto new_s2 = regex_replace(s2, make_regex(R"((\w+$))"), "shit");
    cout << new_s2 << endl;
    // hello shit
}

int main(int argc, char* argv[]) {
    /* t1(); */
    /* t2(); */
    t3();
    return 0;
}
