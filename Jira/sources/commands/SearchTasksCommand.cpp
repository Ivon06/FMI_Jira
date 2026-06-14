#include "../../headers/commands/SearchTasksCommand.h"
#include "../../headers/services/TaskService.h"

void SearchTasksCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument(
            "Usage: search-tasks <keyword>");
    }

    auto tasks =
        TaskService::searchTasks(
            context,
            args[0]);

    if (tasks.empty()) {
        std::cout << "[System] No tasks found."
            << std::endl;
        return;
    }

    for (Task* task : tasks) {
        std::cout << *task << std::endl;
    }
}