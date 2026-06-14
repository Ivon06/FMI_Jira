#include "../../headers/commands/ListAllProjectsCommand.h"
#include "../../headers/services/UserService.h"

#include <iostream>
#include <stdexcept>

ListAllProjectsCommand::ListAllProjectsCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ListAllProjectsCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: list-all-projects");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr || currentUser->getRole() != UserRole::Lecturer) {
        throw std::runtime_error("Only lecturer can list all projects.");
    }

    for (const Project& project : context.getProjects()) {
        std::cout << project << std::endl;
    }
}