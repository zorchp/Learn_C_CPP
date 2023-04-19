class Poly;
typedef Poly P;
class LiLei {
    friend class Poly; // C++98通过, C++11通过
};
class Jim {
    friend Poly; // C++98失败, C++11通过
};
class HanMeiMei {
    friend P; // C++98失败, C++11通过
};
// 编译选项:g++ -std=c++11 2-9-1.cpp
