#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

std::mutex m;
std::vector<std::string> urls;

void crawl(const std::string& url) {
    // 爬取指定 URL 的内容。
    // 这里只是模拟爬取过程，因此只是简单地输出 URL。
    std::cout << "Crawling: " << url << std::endl;
}

void process_urls() {
    while (true) {
        std::string url;
        m.lock();
        if (urls.empty()) {
            m.unlock();
            break;
        }
        url = urls.back();
        urls.pop_back();
        m.unlock();
        crawl(url);
    }
}

int main() {
    // 创建线程数量为 4 的线程池。
    std::vector<std::thread> thread_pool;
    for (int i = 0; i < 4; ++i) { thread_pool.emplace_back(process_urls); }

    // 将要爬取的 URL 添加到 urls 向量中。
    // 这里只是添加了一些示例 URL，您可以按照实际情况更改这些 URL。
    urls.emplace_back("https://www.example.com/");
    urls.emplace_back("https://www.example.org/");
    urls.emplace_back("https://www.example.net/");
    urls.emplace_back("https://www.example.io/");

    // 等待所有线程完成工作。
    for (auto& thread : thread_pool) { thread.join(); }

    return 0;
}
