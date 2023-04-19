class P;
template <typename T>
class People {
    friend T;
};
People<P> PP;   // 类型P在这里是People类型的友元
People<int> Pi; // 对于int类型模板参数，友元声明被忽略
                // 编译选项:g++ -std=c++11 2-9-2.cpp
