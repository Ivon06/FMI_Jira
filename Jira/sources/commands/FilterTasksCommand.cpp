#include "../../headers/commands/FilterTasksCommand.h"
#include "../../headers/services/TaskService.h"

FilterTasksCommand::FilterTasksCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void FilterTasksCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument(
            "Usage: filter-tasks <status>");
    }

    auto tasks =
        TaskService::filterByStatus(
            context,
            stringToTaskStatus(args[0]));

    if (tasks.empty()) {
        std::cout << "[System] No matching tasks."
            << std::endl;
        return;
    }

    for (Task* task : tasks) {
        std::cout << *task << std::endl;
    }
}