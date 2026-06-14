#include "../../headers/commands/ListAllTasksCommand.h"
#include "../../headers/services/UserService.h"

#include <iostream>
#include <stdexcept>

ListAllTasksCommand::ListAllTasksCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ListAllTasksCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: list-all-tasks");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr ||
        (currentUser->getRole() != UserRole::Lecturer &&
            currentUser->getRole() != UserRole::TeachingAssistant)) {
        throw std::runtime_error("Only lecturer or teaching assistant can list all tasks.");
    }

    for (const Task& task : context.getTasks()) {
        std::cout << task << std::endl;
    }
}