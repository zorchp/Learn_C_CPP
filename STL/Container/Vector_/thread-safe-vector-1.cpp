#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void add_vector(int range, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < range; i++) {
        vec.push_back(rand());
    }
}
int main() {
    vec.reserve(100);
    thread t1 = thread(add_vector, 1000, 2);
    thread t2 = thread(add_vector, 1000, 1);

    t1.join();
    t2.join();
}
