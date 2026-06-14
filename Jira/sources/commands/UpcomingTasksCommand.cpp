#include "../../headers/commands/UpcomingTaskCommand.h"
#include "../../headers/services/UserService.h"

#include <iostream>
#include <stdexcept>
#include <ctime>

UpcomingTasksCommand::UpcomingTasksCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void UpcomingTasksCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: upcoming-tasks");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr) {
        throw std::runtime_error("No logged user.");
    }

    std::time_t now = std::time(nullptr);
    bool found = false;

    for (const Task& task : context.getTasks()) {
        if (task.getAssigneeId() == currentUser->getId() &&
            task.getStatus() != TaskStatus::Done &&
            task.getDeadline() >= now) {

            std::cout << task << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "[System] No upcoming tasks." << std::endl;
    }
}