#include "../../headers/stages/StageValidator.h"
#include <stdexcept>

void StageValidator::validateName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Stage name cannot be empty.");
    }
}

void StageValidator::validateDates(std::time_t startDate,
    std::time_t endDate) {
    if (endDate < startDate) {
        throw std::invalid_argument("Stage end date cannot be before start date.");
    }
}