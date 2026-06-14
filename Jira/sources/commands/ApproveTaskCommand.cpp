#include "../../headers/commands/ApproveTaskCommand.h"
#include "../../headers/services/TaskService.h"

#include <iostream>
#include <stdexcept>

ApproveTaskCommand::ApproveTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ApproveTaskCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: approve-task <task_id>");
    }

    TaskService::approveTask(context, std::stoul(args[0]));

    std::cout << "[System] Task approved." << std::endl;
}