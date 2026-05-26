#include "../../headers/commands/CreateProjectCommand.h"
#include "../../headers/services/ProjectService.h"

#include <iostream>
#include <stdexcept>

CreateProjectCommand::CreateProjectCommand(
    const std::vector<std::string>& args)
    : Command(args) {
}

void CreateProjectCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument(
            "Usage: create-project <name> <description>");
    }

    std::string description;

    for (size_t i = 1; i < args.size(); i++) {
        if (i > 1) {
            description += " ";
        }

        description += args[i];
    }

    ProjectService::createProject(context, args[0], description);

    std::cout << "[System] Project '"
        << args[0]
        << "' created successfully.\n";
}