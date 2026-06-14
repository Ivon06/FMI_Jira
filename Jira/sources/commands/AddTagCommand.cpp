#include "../../headers/commands/AddTagCommand.h"
#include "../../headers/services/TaskService.h"

AddTagCommand::AddTagCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void AddTagCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument(
            "Usage: add-tag <task_id> <tag>");
    }

    TaskService::addTag(
        context,
        std::stoul(args[0]),
        args[1]);

    std::cout << "[System] Tag added successfully."
        << std::endl;
}