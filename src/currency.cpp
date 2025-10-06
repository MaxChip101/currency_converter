#include "currency.h"


#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <print>

using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

void InitCurrency() {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "");
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
    }

}