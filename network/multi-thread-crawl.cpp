#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/socket.h>

using namespace std;

const int THREAD_COUNT = 5;

// 定义线程参数结构体
struct ThreadArgs {
    int threadId;
    string url;
};

// 定义工作线程函数
void *work(void *args) {
    ThreadArgs *threadArgs = (ThreadArgs *)args;

    // 解析网址
    string host;
    string path;
    int port;
    size_t found = threadArgs->url.find("://");
    if (found != string::npos) {
        host = threadArgs->url.substr(found + 3);
    } else {
        host = threadArgs->url;
    }
    found = host.find("/");
    if (found != string::npos) {
        path = host.substr(found);
        host = host.substr(0, found);
    } else {
        path = "/";
    }
    found = host.find(":");
    if (found != string::npos) {
        port = atoi(host.substr(found + 1).c_str());
        host = host.substr(0, found);
    } else {
        port = 80;
    }

    // 获取主机 IP 地址
    struct hostent *hostinfo = gethostbyname(host.c_str());
    if (hostinfo == NULL) {
        cerr << "无法解析主机名：" << host << endl;
        exit(1);
    }
    struct in_addr **addrs = (struct in_addr **)hostinfo->h_addr_list;

    // 创建套接字
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) { cerr << "创建套接字失败！" << endl; }
}


int main() {
    // 创建工作线程
    pthread_t threads[THREAD_COUNT];
    ThreadArgs threadArgs[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        threadArgs[i].threadId = i;
        threadArgs[i].url = "http://www.example.com";
        pthread_create(&threads[i], NULL, work, &threadArgs[i]);
    }

    // 等待工作线程结束
    for (int i = 0; i < THREAD_COUNT; i++) { pthread_join(threads[i], NULL); }

    return 0;
}
