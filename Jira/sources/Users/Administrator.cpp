#include "..\..\headers\users\Administrator.h"
#include "..\..\headers\users\UserRole.hpp"

Administrator* Administrator::instance = nullptr;

Administrator::Administrator(const std::string& username,
    const std::string& password)
    : User(username,
        password,
        UserRole::Administrator) {
}

Administrator::Administrator(unsigned int id,
    const std::string& username,
    const std::string& password)
    : User(id,
        username,
        password,
        UserRole::Administrator) {
}

void Administrator::print(std::ostream& os) const {
    User::print(os);

    os << "Permissions: Full system access\n";
}

Administrator& Administrator::getInstance() {

    if (instance == nullptr) {

        instance =
            new Administrator(
                "admin",
                "admin");
    }

    return *instance;
}

Administrator& Administrator::getInstance(
    unsigned int id,
    const std::string& username,
    const std::string& password) {

    if (instance == nullptr) {

        instance =
            new Administrator(
                id,
                username,
                password);
    }

    return *instance;
}

void Administrator::destroyInstance() {

    delete instance;
    instance = nullptr;
}

bool Administrator::canManageUsers() const {
    return true;
}

bool Administrator::canManageProjects() const {
    return true;
}

bool Administrator::canSaveLoadData() const  {
    return true;
}