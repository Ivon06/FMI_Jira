#include "..\..\headers\users\User.h"
#include <stdexcept>
#include <string>
#include "..\..\headers\users\UserRole.hpp"

unsigned int User::nextId = 1;

User::User(const std::string& username, const std::string& password, UserRole role) : id(nextId++), username(username), password(password), role(role)
{
	
}

User::User(unsigned int id, const std::string& username, const std::string& password, UserRole role) : id(id), username(username), password(password), role(role)
{

}

const unsigned int User::getId() const {
    return id;
}

const std::string User::getUsername() const {
    return username;
}

const UserRole User::getRole() const {
    return role;
}

bool User::checkPassword(const std::string& inputPassword) const
{
	return inputPassword == password;
}
void User::changePassword(const std::string& oldPassword, const std::string& newPassword)
{
	if (checkPassword(oldPassword)) {
		password = newPassword;
	}
	else {
		throw std::invalid_argument("Old password is incorrect.");
	}
}

bool User::canCreateTask() const {
    return false;
}

bool User::canApproveTask() const {
    return false;
}

bool User::canReviewTask() const {
    return false;
}

bool User::canChangePriority() const {
    return false;
}

bool User::canManageStages() const {
    return false;
}

bool User::canGradeTask() const {
    return false;
}

bool User::canManageUsers() const {
    return false;
}

bool User::canManageProjects() const {
    return false;
}

bool User::canSaveLoadData() const {
    return false;
}


void User::print(std::ostream& os) const {
    os << "--- User Profile ---\n"
        << "ID: " << id << "\n"
        << "Username: " << username << "\n"
        << "Role: " << roleToString(role) << "\n";
}

void User::serialize(std::ostream& os) const {
    os << id << '\n'
        << username << '\n'
        << password << '\n'
        << static_cast<int>(role) << '\n';
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    user.print(os);
    return os;
}