#include "../../headers/users/Administrator.h"

Administrator::Administrator(const std::string& username,
    const std::string& password)
    : User(username, password, UserRole::Administrator) {
}

Administrator::Administrator(unsigned int id,
    const std::string& username,
    const std::string& password)
    : User(id, username, password, UserRole::Administrator) {
}

void Administrator::print(std::ostream& os) const {
    User::print(os);
}

bool Administrator::canManageUsers() const {
    return true;
}

bool Administrator::canManageProjects() const {
    return true;
}

bool Administrator::canSaveLoadData() const {
    return true;
}