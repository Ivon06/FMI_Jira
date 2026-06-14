#include "../../headers/commands/HelpCommand.h"

#include <iostream>
#include <stdexcept>

HelpCommand::HelpCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void HelpCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: help");
    }

    std::cout << "Available commands:\n";
    std::cout << "login <username> <password>\n";
    std::cout << "logout\n";
    std::cout << "register <username> <password> <role>\n";
    std::cout << "view-profile\n";
    std::cout << "create-project <project_name>\n";
    std::cout << "archive-project <project_name>\n";
    std::cout << "add-user-to-project <username> <project_name>\n";
    std::cout << "remove-user <username>\n";
    std::cout << "join-project <project_name>\n";
    std::cout << "list-projects\n";
    std::cout << "list-all-projects\n";
    std::cout << "create-task <project> <type> <priority>\n";
    std::cout << "assign-task <task_id>\n";
    std::cout << "review-task <task_id>\n";
    std::cout << "approve-task <task_id>\n";
    std::cout << "change-task-status <task_id> <status>\n";
    std::cout << "change-task-priority <task_id> <priority>\n";
    std::cout << "grade-task <task_id> <grade>\n";
    std::cout << "add-comment <task_id>\n";
    std::cout << "add-tag <task_id> <tag>\n";
    std::cout << "save\n";
    std::cout << "load\n";
    std::cout << "exit\n";
}