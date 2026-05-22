#include "../../headers/users/UserValidator.h"
#include "../../headers/Constants.h"
#include <stdexcept>
#include <cctype>

bool UserValidator::validateUsername(const std::string& username) {
    if (username.size() < Constants::User::MIN_USERNAME_LENGTH ||
        username.size() > Constants::User::MAX_USERNAME_LENGTH) {
        throw std::invalid_argument("Invalid username length.");
    }

    for (size_t i = 0; i < username.length(); ++i) {
        char ch = username[i];

        bool isLower = (ch >= 'a' && ch <= 'z');
        bool isUpper = (ch >= 'A' && ch <= 'Z');
        bool isDigit = (ch >= '0' && ch <= '9');
        bool isUnderscore = (ch == '_');

        if (!isLower && !isUpper && !isDigit && !isUnderscore) {
            throw std::invalid_argument("Username can only contain alphanumeric characters and underscores.");
        }
    }

    return true;
}

bool UserValidator::validatePassword(const std::string& password) {
    if (password.size() < Constants::User::MIN_PASSWORD_LENGTH ||
        password.size() > Constants::User::MAX_PASSWORD_LENGTH) {
        throw std::invalid_argument("Invalid password length.");
    }

    for (size_t i = 0; i < password.length(); ++i) {
        char ch = password[i];

        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            throw std::invalid_argument("Password cannot contain spaces or control characters.");
        }
    }

    return true;
}