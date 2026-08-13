#include <unistd.h>
#include <chrono>
#include <iomanip>

inline std::string GetCurrentTimeMs() {
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  now.time_since_epoch()) %
              1000;
    auto timer = std::chrono::system_clock::to_time_t(now);

    std::tm bt;
#if defined(_WIN32)
    localtime_s(&bt, &timer);
#else
    localtime_r(&timer, &bt);
#endif
    std::ostringstream oss;
    oss << std::put_time(&bt, "%Y-%m-%d %H:%M:%S") << "." << std::setfill('0')
        << std::setw(3) << ms.count();
    return oss.str();
}

inline FILE* GetLogFile() {
    static FILE* file = []() {
        const char* log_path = getenv("LOG_FILE");
        if (!log_path) log_path = "my.llm.log";
        FILE* f = fopen(log_path, "a");
        if (!f) {
            // 如果打不开文件，也输出到stderr而不是stdout
            fprintf(stderr, "Failed to open log file: %s\n", log_path);
            return stderr; // 改为stderr，避免和stdout混淆
        }
        fprintf(f,
                "\n%s ================== Program Started ===================\n",
                GetCurrentTimeMs().c_str());
        fflush(f);
        return f;
    }();
    return file;
}

#define MY_LOG(level, fmt, ...)                                 \
    do {                                                        \
        FILE* _f = GetLogFile();                                \
        fprintf(_f, "[%s][" #level "][%s:%d][%s] " fmt "\n",    \
                GetCurrentTimeMs().c_str(), __FILE__, __LINE__, \
                __PRETTY_FUNCTION__, ##__VA_ARGS__);            \
        fflush(_f);                                             \
    } while (0)

#define DLOG(fmt, ...) MY_LOG(DEBUG, fmt, ##__VA_ARGS__)
#define ILOG(fmt, ...) MY_LOG(INFO, fmt, ##__VA_ARGS__)
#define WLOG(fmt, ...) MY_LOG(WARN, fmt, ##__VA_ARGS__)
#define ELOG(fmt, ...) MY_LOG(ERROR, fmt, ##__VA_ARGS__)

