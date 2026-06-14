#pragma once

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

inline std::time_t parseDate(const std::string& date) {
    std::tm tm = {};

    std::istringstream iss(date);
    iss >> std::get_time(&tm, "%d-%m-%Y");

    if (iss.fail()) {
        throw std::invalid_argument("Invalid date format. Use DD-MM-YYYY.");
    }

    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;

    return std::mktime(&tm);
}

inline std::string formatDate(std::time_t time) {
    std::tm tm{};

    localtime_s(&tm, &time);

    std::ostringstream oss;

    oss << std::put_time(&tm, "%d.%m.%Y");

    return oss.str();
}