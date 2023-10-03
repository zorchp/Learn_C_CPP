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

int work() {
    this_thread::sleep_for(2s);
    return 42;
}

int main(int argc, char* argv[]) {
    packaged_task<int()> task(work);
    auto fut = task.get_future();
    scoped_thread th{std::move(task)};
    this_thread::sleep_for(1s);
    cout << "waiting...\n";
    cout << "ans = " << fut.get() << endl;
    return 0;
}
