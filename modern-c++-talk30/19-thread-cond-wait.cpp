#include <chrono>
#include <condition_variable>
#include <utility>
#include <iostream>
#include <format>
#include <mutex>
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

void work(condition_variable& cv, int& result) {
    this_thread::sleep_for(2s);
    result = 42;
    cv.notify_one();
}

int main(int argc, char* argv[]) {
    condition_variable cv;
    mutex cv_mut;
    int result;
    scoped_thread th(work, ref(cv), ref(result));
    cout << "waiting...\n";
    unique_lock lock(cv_mut);
    cv.wait(lock);
    cout << "ans is " << result << '\n';
    return 0;
}
