#include "../../headers/stages/StageValidator.h"
#include "../../headers/Constants.h"
#include <stdexcept>

void StageValidator::validateName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Stage name cannot be empty.");
    }

    if (name.size() > Constants::Stage::MAX_NAME_LENGTH) {
        throw std::invalid_argument("Stage name is too long.");
    }
}

void StageValidator::validateDates(std::time_t startDate,
    std::time_t endDate) {
    if (endDate < startDate) {
        throw std::invalid_argument("Stage end date cannot be before start date.");
    }
}