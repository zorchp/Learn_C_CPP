#include <iostream>
#include <string>
#include "curl/curl.h"

int main() {
    std::string url = "https://www.qq.com";
    const char* urls = url.c_str();

    CURL* curl_handle;
    curl_global_init(CURL_GLOBAL_ALL);

    if (!(curl_handle = curl_easy_init())) return -1;
    curl_easy_setopt(curl_handle, CURLOPT_URL, urls);
    CURLcode res = curl_easy_perform(curl_handle);
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    return 0;
}
