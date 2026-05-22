#include "../../headers/projects/ProjectValidator.h"
#include <stdexcept>

void ProjectValidator::validateName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Project name cannot be empty.");
    }

    if (name.size() > 100) {
        throw std::invalid_argument("Project name is too long.");
    }
}

void ProjectValidator::validateDescription(const std::string& description) {
    if (description.size() > 500) {
        throw std::invalid_argument("Project description is too long.");
    }
}