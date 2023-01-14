#include <array>
#include <cstring>
#include <fstream>
#include <curl/curl.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include "../include/func.hpp"

static size_t WriteCallback(void *content, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)content, size * nmemb);
    return size * nmemb;
}

Kekpm::Kekpm(char **av, int ac)
{
    if (ac == 1) {
// Display help menu
        this->display_help();
        return;
    }
    cmd = av[1];
}

int Kekpm::exec_cmd(void)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    const char *path = NULL;
    std::array<std::string, 2> fileList{"Makefile", "main.cpp"};
    std::string url = URL;
    std::fstream file;
    std::string completeUrl;

    curl = curl_easy_init();
    if (curl) {
        for (const std::string& text : fileList) {
            readBuffer.clear(); // clear the buffer string
            completeUrl = url + text;
            file.open(text, std::ios_base::out);
            if (!file.is_open()) {
                std::cerr << "Unable to open the file " << text <<  std::endl;
                return 84;
            }
            std::cout << "Request sent to: " << completeUrl << std::endl;
            curl_easy_setopt(curl, CURLOPT_URL, completeUrl.c_str()); // request to the server
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            file << readBuffer;
            file.close();
            std::cout << res << std::endl;
        }
        curl_easy_cleanup(curl);

    } else {
        std::cerr << "Sorry, cannot send request to this url" << std::endl;
    }
    return 0;
}

void Kekpm::display_help(void)
{
    std::cout << "Help menu" << std::endl;
}

Kekpm::~Kekpm(void)
{

}


