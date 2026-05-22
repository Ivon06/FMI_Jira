#include "..\..\headers\users\Lecturer.h"
#include "..\..\headers\users\UserRole.hpp"


Lecturer::Lecturer(const std::string& username,
    const std::string& password)
    : User(username,
        password,
        UserRole::Lecturer) {
}

Lecturer::Lecturer(unsigned int id,
    const std::string& username,
    const std::string& password)
    : User(id,
        username,
        password,
        UserRole::Lecturer) {
}

void Lecturer::print(std::ostream& os) const {
    User::print(os);
}

bool Lecturer::canApproveTask() const {
    return true;
}

bool Lecturer::canReviewTask() const {
    return true;
}

bool Lecturer::canChangePriority() const {
    return true;
}

bool Lecturer::canManageStages() const {
    return true;
}

bool Lecturer::canGradeTask() const {
    return true;
}

bool Lecturer::canManageProjects() const {
    return true;
}