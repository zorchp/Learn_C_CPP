#include <iostream>
#include <iterator>


int main(int argc, char const *argv[]) {
    double v1, v2;
    std::istream_iterator<double> eos; //结束标志符
    //======================cin=================
    std::cout << "input two numbers: " << std::endl;
    std::istream_iterator<double> iit(std::cin);
    if (iit != eos) v1 = *iit;
    ++iit; //不断读取内容
    if (iit != eos) v2 = *iit;
    std::cout << v1 << "*" << v2 << "=" << v1 * v2 << std::endl;
    return 0;
}