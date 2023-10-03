#include <utility>
#include <iostream>
#include <format>
#include <mutex>
#include <thread>

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
std::mutex output_lock;
void func(const char* name) {
    // this_thread::sleep_for(100ms);
    // lock_guard<mutex> guard{output_lock};
    std::cout << std::format("thread {}\n", name);
    // cout << "thread " << name << '\n';
}

void t1() {
    scoped_thread t1{func, "A"};
    scoped_thread t2{func, "B"};
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
