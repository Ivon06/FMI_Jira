#include "../../headers/commands/AddUserToProjectCommand.h"
#include "../../headers/services/ProjectService.h"

#include <iostream>
#include <stdexcept>

AddUserToProjectCommand::AddUserToProjectCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void AddUserToProjectCommand::execute(Context& context) {

    if (args.size() != 2) {
        throw std::invalid_argument(
            "Usage: add-user-to-project <username> <project_name>");
    }

    ProjectService::addUserToProject(
        context,
        args[0],
        args[1]);

    std::cout
        << "[System] User "
        << args[0]
        << " added to project "
        << args[1]
        << '.'
        << std::endl;
}