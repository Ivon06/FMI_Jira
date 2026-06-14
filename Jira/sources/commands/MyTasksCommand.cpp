#include "../../headers/commands/MyTasksCommand.h"
#include "../../headers/services/UserService.h"
#include <iostream>
#include <stdexcept>

MyTasksCommand::MyTasksCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void MyTasksCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: my-tasks");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr) {
        throw std::runtime_error("No logged user.");
    }

    bool found = false;

    for (const Task& task : context.getTasks()) {
        if (task.getAssigneeId() == currentUser->getId()) {
            std::cout << task << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "[System] You have no assigned tasks." << std::endl;
    }
}