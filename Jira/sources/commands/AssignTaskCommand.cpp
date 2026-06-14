#include "../../headers/commands/AssignTaskCommand.h"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

AssignTaskCommand::AssignTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void AssignTaskCommand::execute(Context& context) {

    if (args.size() != 1) {
        throw std::invalid_argument(
            "Usage: assign-task <task_id>");
    }

    TaskService::assignTask(context, std::stoul(args[0]));

    std::cout << "[System] Task assigned successfully" << std::endl;

}