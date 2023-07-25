#include <cstring>
#include <iostream>

class BigMemoryPool {
public:
    static const int PoolSize = 4096;
    BigMemoryPool() : pool_(new char[PoolSize]) {}
    ~BigMemoryPool() {
        if (pool_ != nullptr) { delete[] pool_; }
    }

    BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize]) {
        // std::cout << "copy big memory pool." << std::endl;
        memcpy(pool_, other.pool_, PoolSize);
    }

private:
    char* pool_;
};

BigMemoryPool get_pool(const BigMemoryPool& pool) { return pool; }

BigMemoryPool make_pool() {
    BigMemoryPool pool;
    return get_pool(pool);
}
/*1．get_pool返回的BigMemoryPool临时对象调用复制构造函数复制了pool对象。
 * 2．make_pool返回的BigMemoryPool临时对象调用复制构造函数复制了get_pool返回的临时对象。
 * 3．main函数中my_pool调用其复制构造函数复制make_pool返回的临时对象。*/
/*int main() {
    BigMemoryPool my_pool = make_pool();
    // copy big memory pool.
    // copy big memory pool.
    // copy big memory pool.
    return 0;
}*/

#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) { BigMemoryPool my_pool = make_pool(); }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to call make_pool :" << diff.count() << " s"
              << std::endl;//Time to call make_pool :0.569196 s
}