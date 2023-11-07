#include <dlfcn.h>
#include <iostream>
using CALC_PI = double (*)();

int main() {
    void* handle = dlopen("libtest.dylib", RTLD_NOW);
    if (!handle) {
        std::cerr << "cannot open dylib\n";
        return -1;
    }
    CALC_PI calc_pi = reinterpret_cast<CALC_PI>(dlsym(handle, "calc_pi"));
    if (!calc_pi) {
        std::cerr << "cannot load dylib\n";
    }
    double pi = calc_pi();
    std::cout << pi << std::endl;
    dlclose(handle);
    return 0;
}
