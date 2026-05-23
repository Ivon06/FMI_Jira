#pragma once
#include <string>
#include "../Context.h"
#include "../users/User.h"

class UserService {
public:
    static void registerUser(Context& context,
        const std::string& username,
        const std::string& password,
        const std::string& role);

    static void login(Context& context,
        const std::string& username,
        const std::string& password);

    static void logout(Context& context);

    static User* getCurrentUser(Context& context);

    static User* findUserById(Context& context,
        unsigned int id);

    static User* findUserByUsername(Context& context,
        const std::string& username);

    static bool usernameExists(Context& context,
        const std::string& username);

private:
    static void requireAdmin(Context& context);
};