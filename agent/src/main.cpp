#include  <iostream>
#include  <string>
#include  <fstream>
#include <thread>
#include <chrono>  
#include "collectors/MemCollector.hpp"
#include "utils/TimeUtils.hpp"
#include "transport/HttpClient.hpp"
#include <nlohmann/json.hpp>


int main(){


MemCollector memCollector;
HttpClient httpClient;

std::string serverUrl = "http://localhost:3000/api/monitor";
std::string deviceId = "jaime-pc-01";



while(true){

    double usage = memCollector.getMemUsage();
    std::string timestamp = TimeUtils::getCurrentTimestamp();

    nlohmann::json payload;
    payload["deviceId"] = deviceId;
    payload["timestamp"] = timestamp;
    payload["ramUsage"] = usage;

    std::string jsonString = payload.dump();

    bool success = httpClient.post(serverUrl, jsonString);

    if (success) {
            std::cout << "[OK] " << timestamp << " | RAM: " << usage << "% -> send" << std::endl;
        } else {
            std::cerr << "Error to send data" << std::endl;
        }


    std::cout << "Memory Usage: " << usage << "%" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Sleep for 5 seconds before the next reading
    

}

return 0;


}