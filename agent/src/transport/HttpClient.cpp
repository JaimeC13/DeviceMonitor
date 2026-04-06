#include "HttpClient.hpp"
#include <curl/curl.h>


bool HttpClient::post(const std::string& url, const std::string& data) {

CURL *curl = curl_easy_init();

if (!curl) return false;

curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

struct curl_slist* headers = NULL;
headers = curl_slist_append(headers, "Content-Type: application/json");
curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

CURLcode res = curl_easy_perform(curl);
curl_slist_free_all(headers);

curl_easy_cleanup(curl);

return res == CURLE_OK;




}