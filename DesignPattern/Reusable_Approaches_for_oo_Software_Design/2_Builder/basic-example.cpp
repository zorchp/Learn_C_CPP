#include <cstdio>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
    std::string words[] = {"hello", "world"};
    std::ostringstream oss;
    oss << "<ul>";
    for (auto w : words) {
        oss << "  <li>" << w << "</li>";
    }
    oss << "</ul>";
    printf("%s\n", oss.str().c_str());
    return 0;
}
