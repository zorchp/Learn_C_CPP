#include <chrono>
#include <iostream>
#include <cstring>

class BigMemoryPool {
public:
    static const int PoolSize = 4096;
    BigMemoryPool() : pool_(new char[PoolSize]) {}
    ~BigMemoryPool() {
        if (pool_ != nullptr) { delete[] pool_; }
    }

    BigMemoryPool(BigMemoryPool&& other) { // move-ctor
        std::cout << "move big memory pool." << std::endl;
        pool_ = other.pool_;
        other.pool_ = nullptr;
    }

    BigMemoryPool& operator=(BigMemoryPool&& other) {
        std::cout << "move(operator=) big memory pool." << std::endl;
        if (pool_ != nullptr) { delete[] pool_; }
        pool_ = other.pool_;
        other.pool_ = nullptr;
        return *this;
    }


    BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize]) {
        std::cout << "copy big memory pool." << std::endl;
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
    // move big memory pool.
    // move big memory pool.
    return 0;
}*/

void t1() { BigMemoryPool my_pool = make_pool(); }


void t2() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) { BigMemoryPool my_pool = make_pool(); }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to call make_pool :" << diff.count() << " s"
              << std::endl; // Time to call make_pool :0.239998 s
}

void t3() {
    BigMemoryPool my_pool;
    my_pool = make_pool();
    /*copy big memory pool.
move big memory pool.
move(operator=) big memory pool.*/
}


void move_pool(BigMemoryPool&& pool) {
    std::cout << "call move_pool" << std::endl;
    // BigMemoryPool my_pool(pool); //为了让这里的构造使用move, 需要强制类型转换
    // BigMemoryPool my_pool(static_cast<BigMemoryPool&&>(pool));
    BigMemoryPool my_pool(std::move(pool)); //函数模板, 用起来方便
}

void t4() {
    move_pool(make_pool());
    /*g++ -std=c++11 -fno-elide-constructors 11-rval-with-move.cc && ./a.out
copy big memory pool.
move big memory pool.
call move_pool
copy big memory pool.*/
    /*use move or static_cast
    copy big memory pool.
move big memory pool.
call move_pool
move big memory pool.*/
}
int main(int argc, char const* argv[]) {
    //g++ -std=c++11 -fno-elide-constructors 11-rval-with-move.cc && ./a.out
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}