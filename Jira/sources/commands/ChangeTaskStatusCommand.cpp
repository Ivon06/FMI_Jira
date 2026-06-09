#include "../../headers/commands/ChangeTaskStatusCommand.h"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

ChangeTaskStatusCommand::ChangeTaskStatusCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ChangeTaskStatusCommand::execute(Context& context) {

    if (args.size() != 2) {
        throw std::invalid_argument(
            "Usage: change-task-status <task_id> <status>");
    }

    TaskService::changeStatus(
        context,
        std::stoul(args[0]),
        stringToTaskStatus(args[1]));
}