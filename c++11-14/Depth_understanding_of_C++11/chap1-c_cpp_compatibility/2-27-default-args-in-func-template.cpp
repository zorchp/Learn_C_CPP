void DefParm(int m = 3) {} // c++98编译通过，c++11编译通过
template <typename T = int>
class DefClass {}; // c++98编译通过，c++11编译通过
template <typename T = int>
void DefTempParm(){}; // c++98编译失败，c++11编译通过
                      // 编译选项:g++ -c -std=c++11 2-11-1.cpp
