#include "../../headers/services/UserService.h"
#include "../../headers/users/UserFactory.h"
#include "../../headers/users/Administrator.h"
#include <stdexcept>

void UserService::registerUser(Context& context,
    const std::string& username,
    const std::string& password,
    const std::string& role) {
    requireAdmin(context);

    if (usernameExists(context, username)) {
        throw std::invalid_argument("Username already exists.");
    }

    context.getUsers().push_back(
        UserFactory::createUser(username, password, role)
    );

    context.markChanged();
}

void UserService::login(Context& context,
    const std::string& username,
    const std::string& password) {
    if (context.isUserLoggedIn()) {
        throw std::runtime_error("User already logged in.");
    }

    User* user = findUserByUsername(context, username);

    if (user == nullptr || !user->checkPassword(password)) {
        throw std::invalid_argument("Invalid username or password.");
    }

    context.setCurrentUserId(user->getId());
}

void UserService::logout(Context& context) {
    if (!context.isUserLoggedIn()) {
        throw std::runtime_error("No user is currently logged in.");
    }

    context.clearCurrentUser();
}

User* UserService::getCurrentUser(Context& context) {
    if (!context.isUserLoggedIn()) {
        return nullptr;
    }

    return findUserById(context, context.getCurrentUserId());
}

User* UserService::findUserById(Context& context,
    unsigned int id) {
    Administrator& admin = Administrator::getInstance();

    if (admin.getId() == id) {
        return &admin;
    }

    for (auto& user : context.getUsers()) {
        if (user->getId() == id) {
            return user.get();
        }
    }

    return nullptr;
}

User* UserService::findUserByUsername(Context& context,
    const std::string& username) {
    Administrator& admin = Administrator::getInstance();

    if (admin.getUsername() == username) {
        return &admin;
    }

    for (auto& user : context.getUsers()) {
        if (user->getUsername() == username) {
            return user.get();
        }
    }

    return nullptr;
}

bool UserService::usernameExists(Context& context,
    const std::string& username) {
    return findUserByUsername(context, username) != nullptr;
}

void UserService::requireAdmin(Context& context) {
    User* currentUser = getCurrentUser(context);

    if (currentUser == nullptr || !currentUser->canManageUsers()) {
        throw std::runtime_error("Only administrator can manage users.");
    }
}