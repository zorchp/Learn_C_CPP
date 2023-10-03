// C++ program to illustrate the above concepts
#include <iostream>
#include <vector>

using namespace std;

// Driver Code
int main() {
    for (std::vector v{1, 2, 3}; auto& e : v) {
        std::cout << e;
    }
    // cout << v.size() << endl;
}
