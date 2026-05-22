
#pragma once
#include <string>

class UserValidator {
public:
     static bool validateUsername(const std::string& username);

    static bool validatePassword(const std::string& password);
};