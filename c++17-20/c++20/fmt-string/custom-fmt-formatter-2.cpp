#include <format>
#include <string>
#include <iostream>
using namespace std;


struct Point {
    int x;
    int y;
};

// just for gcc
template <>
struct std::formatter<Point> : std::formatter<std::string> {
    auto format(Point p, format_context& ctx) const {
        // return formatter<string>::format(std::format("[{}, {}]", p.x, p.y),
        //                                  ctx);
        return std::format_to(ctx.out(), "[{} : {}]", p.x, p.y);
    }
};


void t1() {
    //
#ifndef __clang__
    cout << format("{}\n", Point{1, 2});
#else
    cout << "not supported\n";
#endif
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
