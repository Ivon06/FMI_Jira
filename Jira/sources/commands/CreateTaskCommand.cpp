#include "../../headers/commands/CreateTaskCommand.h"
#include "../../headers/services/TaskService.h"
#include "../../headers/tasks/Task.h"

#include <stdexcept>

CreateTaskCommand::CreateTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void CreateTaskCommand::execute(Context& context) {

    if (args.size() != 7) {
        throw std::invalid_argument(
            "Usage: create-task <project> <title> <description> <type> <priority> <deadline> <points>");
    }

    TaskService::createTask(
        context,
        args[0],
        args[1],
        args[2],
        stringToTaskType(args[3]),
        stringToTaskPriority(args[4]),
        std::stoll(args[5]),
        std::stoi(args[6]));
}