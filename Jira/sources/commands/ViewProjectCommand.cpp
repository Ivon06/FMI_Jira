#include "../../headers/commands/ViewProjectCommand.h"
#include "../../headers/services/ProjectService.h"
#include <iostream>
#include <stdexcept>

ViewProjectCommand::ViewProjectCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ViewProjectCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: view-project <project_name>");
    }

    Project* project = ProjectService::findProjectByName(context, args[0]);

    if (project == nullptr) {
        throw std::invalid_argument("Project does not exist.");
    }

    std::cout << *project;
}