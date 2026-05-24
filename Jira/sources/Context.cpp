#include "../headers/Context.h"
#include <stdexcept>
#include "../headers/users/Administrator.h"

Context::Context()
    : currentUserId(0),
    hasLoggedUser(false),
    hasUnsavedChanges(false) {
    

    if (this->users.size() == 0) {
        seedAdmin();
    }
}

void Context::seedAdmin() {
    users.push_back(
        std::make_unique<Administrator>("admin", "admin")
    );
}

std::vector<std::unique_ptr<User>>& Context::getUsers() {
    return users;
}

const std::vector<std::unique_ptr<User>>& Context::getUsers() const {
    return users;
}

std::vector<Project>& Context::getProjects() {
    return projects;
}

const std::vector<Project>& Context::getProjects() const {
    return projects;
}

std::vector<Task>& Context::getTasks() {
    return tasks;
}

const std::vector<Task>& Context::getTasks() const {
    return tasks;
}

void Context::setCurrentUserId(unsigned int userId) {
    currentUserId = userId;
    hasLoggedUser = true;
}

void Context::clearCurrentUser() {
    currentUserId = 0;
    hasLoggedUser = false;
}

bool Context::isUserLoggedIn() const {
    return hasLoggedUser;
}

unsigned int Context::getCurrentUserId() const {
    if (!hasLoggedUser) {
        throw std::runtime_error("No user is currently logged in.");
    }

    return currentUserId;
}

void Context::markChanged() {
    hasUnsavedChanges = true;
}

void Context::markSaved() {
    hasUnsavedChanges = false;
}

bool Context::hasChanges() const {
    return hasUnsavedChanges;
}