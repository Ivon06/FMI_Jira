#include "../../headers/commands/CreateTaskCommand.h"
#include "../../headers/services/TaskService.h"
#include "../../headers/tasks/Task.h"

#include <iostream>
#include <stdexcept>

CreateTaskCommand::CreateTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void CreateTaskCommand::execute(Context& context) {
    if (args.size() != 3) {
        throw std::invalid_argument("Usage: create-task <project> <type> <priority>");
    }

    std::string title;
    std::string description;

    std::cout << "Title: ";
    std::getline(std::cin, title);

    std::cout << "Description: ";
    std::getline(std::cin, description);

    TaskService::createTask(context, args[0], title, description, stringToTaskType(args[1]), stringToTaskPriority(args[2]));

    std::cout << "[System] Task created successfully." << std::endl;
}