#include <chrono>
#include <iostream>
#include <future>
#include <thread>

using namespace std;

class scoped_thread {
public:
    template <typename... Arg>
    scoped_thread(Arg&&... arg) : thread_(std::forward<Arg>(arg)...) {}

    scoped_thread(scoped_thread&& other) : thread_(std::move(other.thread_)) {}

    scoped_thread(const scoped_thread&) = delete;
    ~scoped_thread() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

private:
    std::thread thread_;
};


void work(promise<int> prom) {
    this_thread::sleep_for(2s);
    prom.set_value(42);
}

int main(int argc, char* argv[]) {
    promise<int> prom;
    auto fut = prom.get_future();
    scoped_thread th{work, std::move(prom)};
    cout << "waiting...\n";
    cout << "ans = " << fut.get() << endl;
    return 0;
}
