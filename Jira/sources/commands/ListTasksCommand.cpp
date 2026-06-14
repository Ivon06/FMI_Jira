#include "../../headers/commands/ListTasksCommand.h"
#include "../../headers/services/UserService.h"

#include <iostream>
#include <stdexcept>

ListTasksCommand::ListTasksCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ListTasksCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: list-tasks");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr) {
        throw std::runtime_error("No logged user.");
    }

    if (currentUser->getRole() != UserRole::Student) {
        throw std::runtime_error("Only students can use list-tasks.");
    }

    bool found = false;

    for (const Task& task : context.getTasks()) {
        if (task.getCreatorId() == currentUser->getId() || task.getAssigneeId() == currentUser->getId()) {
            std::cout << task << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "[System] No tasks found." << std::endl;
    }
}