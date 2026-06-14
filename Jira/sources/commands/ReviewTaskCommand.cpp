#include "../../headers/commands/ReviewTaskCommand.h"
#include "../../headers/services/TaskService.h"

#include <iostream>
#include <stdexcept>

ReviewTaskCommand::ReviewTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ReviewTaskCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: review-task <task_id>");
    }

    TaskService::reviewTask(context, std::stoul(args[0]));

    std::cout << "[System] Task sent for review." << std::endl;
}