#include "../../headers/commands/CreateProjectCommand.h"
#include "../../headers/services/ProjectService.h"

#include <iostream>
#include <stdexcept>

CreateProjectCommand::CreateProjectCommand(
    const std::vector<std::string>& args)
    : Command(args) {
}

void CreateProjectCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument(
            "Usage: create-project <name>");
    }

    std::string description;

    std::cout << "Description: ";
    std::getline(std::cin, description);

    ProjectService::createProject(
        context,
        args[0],
        description);

    std::cout << "[System] Project created successfully."
        << std::endl;
}