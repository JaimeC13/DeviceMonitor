#include "TimeUtils.hpp"
#include <chrono>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>


std::string TimeUtils::getCurrentTimestamp() {

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;

    ss<< std::put_time(std::gmtime(&in_time_t), "%Y-%m-%dT%H:%M:%SZ");

    return ss.str();
 }
