#include <curl/curl.h>
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

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8000");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
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


