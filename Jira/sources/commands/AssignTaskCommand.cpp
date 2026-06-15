#include "../../headers/commands/AssignTaskCommand.h"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

AssignTaskCommand::AssignTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void AssignTaskCommand::execute(Context& context) {

    if (args.size() < 1) {
        throw std::invalid_argument(
            "Usage: assign-task <task_title>");
    }

    std::string name = "";

    for (int i = 0; i < args.size(); i++)
    {
        name += args[i] + ' ';
    }

    while (!name.empty() && name.back() == ' ') {
        name.pop_back();
    }

    Task* task = TaskService::findTaskByName(context, name);

    if (!task)
    {
        throw std::invalid_argument("Task does not exist");
    }

    TaskService::assignTask(context, task->getId());

    std::cout << "[System] Task assigned successfully" << std::endl;

}