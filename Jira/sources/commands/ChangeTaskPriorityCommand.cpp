#include "../../headers/commands/ChangeTaskPriorityCommand.h"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

ChangeTaskPriorityCommand::ChangeTaskPriorityCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ChangeTaskPriorityCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument("Usage: change-task-priority <task_id> <priority>");
    }

    TaskService::changePriority(context, std::stoul(args[0]), stringToTaskPriority(args[1]));

    std::cout << "[System] Task priority changed successfully." << std::endl;
}