namespace NS {
class Q {};
void display(const Q &) {} //这里声明的函数也将被添加到候选函数集中
} // namespace NS
class B : public NS::Q {};

int main(int argc, char const *argv[]) {
    B b1;
    display(b1); //调用语句的候选函数在调用语句所在的scope中查找,
                 //也应在B以及基类Q所属的namespace中找

    return 0;
}