#pragma once

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

inline std::string formatDate(std::time_t time) {
    std::tm tm{};

    localtime_s(&tm, &time);

    std::ostringstream oss;

    oss << std::put_time(&tm, "%d.%m.%Y");

    return oss.str();
}