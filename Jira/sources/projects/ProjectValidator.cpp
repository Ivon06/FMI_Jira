#include "../../headers/projects/ProjectValidator.h"
#include "../../headers/Constants.h"
#include <stdexcept>

void ProjectValidator::validateName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Project name cannot be empty.");
    }

    if (name.size() > Constants::Project::MAX_NAME_LENGTH) {
        throw std::invalid_argument("Project name is too long.");
    }
}

void ProjectValidator::validateDescription(const std::string& description) {
    if (description.size() > Constants::Project::MAX_DESCRIPTION_LENGTH) {
        throw std::invalid_argument("Project description is too long.");
    }
}