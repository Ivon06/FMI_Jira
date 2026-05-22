#pragma once
#include <string>

class ProjectValidator {
public:
    static void validateName(const std::string& name);

    static void validateDescription(const std::string& description);
};