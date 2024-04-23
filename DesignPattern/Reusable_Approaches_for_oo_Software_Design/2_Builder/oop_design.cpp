#include <cstdio>
#include <string>
#include <vector>

struct HtmlElement {
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;

    HtmlElement() = default;

    HtmlElement(const std::string &name, const std::string &text)
        : name(name), text(text) {}

    std::string str(int indent = 0) const {
        // pretty print the contents
        return name + text;
    }
};

int main(int argc, char *argv[]) {
    std::string words[] = {"hello", "world"};
    HtmlElement list{"ul", ""};
    for (auto w : words) {
        list.elements.emplace_back(HtmlElement{"li", w});
    }
    printf("%s\n", list.str().c_str());
    return 0;
}
