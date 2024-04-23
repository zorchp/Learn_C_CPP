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

struct HtmlBuilder {
    HtmlElement root;

    HtmlBuilder(std::string root_name) { root.name = root_name; }

    void add_child(std::string child_name, std::string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
    }

    std::string str() { return root.str(); }
};
