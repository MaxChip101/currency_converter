#include "currency.h"

#include <fstream>
#include <curl/curl.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <nlohmann/json.hpp>
#include <print>
#include <string>

using json = nlohmann::json;

std::string input = "0";
double input_number = 0;
double output = 0;

std::string selected_input_currency = "USD";
std::string selected_output_currency = "USD";
std::string base = "";
std::map<std::string, double> rates;

bool left_right_selection = false;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

void InitCurrency(std::string key) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        std::string url = "https://v6.exchangerate-api.com/v6/" + key + "/latest/USD";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "CurrencyConverter/1.0");
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::printf("curl error: %s\n", curl_easy_strerror(res));
            exit(1);
        }
        curl_easy_cleanup(curl);
    }

    json data = json::parse(response);

    base = data["base_code"].get<std::string>();
    
    json::iterator it;
    for (it = data["conversion_rates"].begin(); it != data["conversion_rates"].end(); it++) {
        double value = it.value().get<double>();
        rates[it.key()] = value;
        SDL_Log(it.key().c_str());
    }

}