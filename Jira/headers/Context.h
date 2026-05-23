#pragma once
#include <vector>
#include <memory>

#include "users/User.h"
#include "projects/Project.h"
#include "tasks/Task.h"

class Context {
private:
    std::vector<std::unique_ptr<User>> users;
    std::vector<Project> projects;
    std::vector<Task> tasks;

    unsigned int currentUserId;
    bool hasLoggedUser;
    bool hasUnsavedChanges;

public:
    Context();

    Context(const Context&) = delete;
    Context& operator=(const Context&) = delete;

    std::vector<std::unique_ptr<User>>& getUsers();
    const std::vector<std::unique_ptr<User>>& getUsers() const;

    std::vector<Project>& getProjects();
    const std::vector<Project>& getProjects() const;

    std::vector<Task>& getTasks();
    const std::vector<Task>& getTasks() const;

    void setCurrentUserId(unsigned int userId);
    void clearCurrentUser();

    bool isUserLoggedIn() const;
    unsigned int getCurrentUserId() const;

    void markChanged();
    void markSaved();
    bool hasChanges() const;
};