#include <iostream>
#include <string_view>
using namespace std;

namespace version1 {

// old version
template <typename TImpl>
class Notifier {
public:
    void AlertSMS(string_view msg) { impl().SendAlertSMS(msg); }

    void AlertEmail(string_view msg) { impl().SendAlertEmail(msg); }

private:
    TImpl& impl() { return static_cast<TImpl&>(*this); }

    // maybe_unused
    // friend TImpl;
};

template <typename TImpl>
void AlertAllChannels(Notifier<TImpl>& notifier, string_view msg) {
    notifier.AlertSMS(msg);
    notifier.AlertEmail(msg);
}

// CRTP
struct TestNotifier : public Notifier<TestNotifier> {
    void SendAlertSMS(string_view msg) { cout << "SMS: " << msg << endl; }

    void SendAlertEmail(string_view msg) { cout << "Email: " << msg << endl; }
};
} // namespace version1

void t1() {
    using namespace version1;
    // worked example, with old style static polymorphism
    TestNotifier tn;
    AlertAllChannels(tn, "testing!"); // just testing!
}

namespace version2 {
// do some constrain
template <typename TImpl>
concept IsANotifier = requires(TImpl impl) {
    impl.AlertSMS(string_view{});
    impl.AlertEmail(string_view{});
};

template <IsANotifier TImpl>
void AlertAllChannels(TImpl& impl, string_view msg) {
    impl.AlertSMS(msg);
    impl.AlertEmail(msg);
}

struct TestNotifier {
    void AlertSMS(string_view msg) { cout << "SMS: " << msg << endl; }

    void AlertEmail(string_view msg) { cout << "Email: " << msg << endl; }
};


} // namespace version2

void t2() {
    using namespace version2;
    TestNotifier tn;
    AlertAllChannels(tn, "testing!"); // just testing!
}

int main(int argc, char* argv[]) {
    t1();
    t2();
    return 0;
}
