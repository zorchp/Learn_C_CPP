#include <format>
#include <string>
#include <iostream>
using namespace std;

class KeyValue {
public:
    KeyValue(string_view key, int value) : m_key(key), m_value(value) {}
    const string &get_key() const { return m_key; }
    int get_value() const { return m_value; }

private:
    string m_key;
    int m_value;
};

// custom formatter

template <>
class std::formatter<KeyValue> {
public:
    constexpr auto parse(auto &context) {
        using enum OutputType;
        auto iter{context.begin()};
        const auto end{context.end()};
        if (iter == end || *iter == '}') {
            m_outputType = KeyAndValue;
            return iter;
        }

        switch (*iter) {
            case 'a':
                m_outputType = KeyOnly;
                break;
            case 'b':
                m_outputType = ValueOnly;
                break;
            case 'c':
                m_outputType = KeyAndValue;
                break;
            default:
                throw format_error{"Invalid KeyValue format specifier"};
        }

        ++iter;
        if (iter != end and *iter != '}') {
            throw format_error{"Invalid KeyValue format specifier"};
        }
        return iter;
    }

    auto format(const KeyValue &kv, auto &context) {
        switch (m_outputType) {
            using enum OutputType;
            case KeyOnly:
                return format_to(context.out(), "{}", kv.get_key());
            case ValueOnly:
                return foramt_to(context.out(), "{}", kv.get_value());
            default:
                return format_to(context.out(), "{} - {}", kv.get_key(),
                                 kv.get_value());
        }
    }

private:
    enum class OutputType { KeyOnly, ValueOnly, KeyAndValue };
    OutputType m_outputType{OutputType::KeyAndValue};
};

void t1() {
    KeyValue kv{"Key1", 11};
    cout << format("{}\n", kv);
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
