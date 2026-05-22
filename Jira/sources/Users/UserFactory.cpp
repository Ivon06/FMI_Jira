#include "../../headers/users/UserFactory.h"
#include "../../headers/users/UserValidator.h" 
#include "../../headers/users/UserRole.hpp" 
#include "../../headers/users/Lecturer.h"
#include "../../headers/users/TeachingAssistant.h"
#include "../../headers/users/Student.h"
#include <stdexcept>
#include <memory>

std::unique_ptr<User> UserFactory::createUser(const std::string& username, const std::string& password, const std::string& roleStr) {

    UserValidator::validateUsername(username);
    UserValidator::validatePassword(password);

    UserRole role;
	role = stringToRole(roleStr); 

    if (role == UserRole::Student) {
        return std::make_unique<Student>(username, password);
    }
    else if (role == UserRole::TeachingAssistant) {
        return std::make_unique<TeachingAssistant>(username, password);
    }
    else if (role == UserRole::Lecturer) {
        return std::make_unique<Lecturer>(username, password);
    }
    else if (role == UserRole::Administrator) {
        throw std::invalid_argument("Administrator is created automatically.");
    }

    throw std::invalid_argument("Unknown role type.");
}

std::unique_ptr<User> UserFactory::restoreUser(unsigned int id, const std::string& username, const std::string& password, const std::string& roleStr) {
  
    UserRole role;
	role = stringToRole(roleStr);

    if (role == UserRole::Student) {
        return std::make_unique<Student>(id, username, password);
    }
    else if (role == UserRole::TeachingAssistant) {
        return std::make_unique<TeachingAssistant>(id, username, password);
    }
    else if (role == UserRole::Lecturer) {
        return std::make_unique<Lecturer>(id, username, password);
    }
    else if (role == UserRole::Administrator) {
        throw std::invalid_argument("Administrator should be restored separately.");
    }


    throw std::invalid_argument("Unknown role type in file.");
}