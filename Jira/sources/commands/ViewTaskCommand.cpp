#include "../../headers/commands/ViewTaskCommand.h"
#include "../../headers/services/TaskService.h"
#include <iostream>
#include <stdexcept>

ViewTaskCommand::ViewTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ViewTaskCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: view-task <task_id>");
    }

    Task* task = TaskService::findTaskById(context, std::stoul(args[0]));

    if (task == nullptr) {
        throw std::invalid_argument("Task does not exist.");
    }

    std::cout << *task;
}