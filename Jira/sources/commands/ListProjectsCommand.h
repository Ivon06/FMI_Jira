#include "../../headers/commands/ListProjectsCommand.h"
#include <iostream>
#include <stdexcept>

ListProjectsCommand::ListProjectsCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ListProjectsCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: list-projects");
    }

    const std::vector<Project>& projects = context.getProjects();

    if (projects.empty()) {
        std::cout << "[System] No projects available." << std::endl;
        return;
    }

    for (const Project& project : projects) {
        std::cout << project << std::endl;
    }
}