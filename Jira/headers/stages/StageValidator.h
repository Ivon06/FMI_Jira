#pragma once
#include <string>
#include <ctime>

class StageValidator {
public:
    static void validateName(const std::string& name);

    static void validateDates(std::time_t startDate,
        std::time_t endDate);
};