#include "../../headers/commands/ListProjectsCommand.h"
#include <iostream>
#include <stdexcept>
#include "../../headers/services/UserService.h"

ListProjectsCommand::ListProjectsCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ListProjectsCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: list-projects");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr) {
        throw std::runtime_error("No logged user.");
    }

    if (currentUser->getRole() != UserRole::Student) {
        throw std::runtime_error("Only students can use list-projects.");
    }

    bool found = false;

    for (const Project& project : context.getProjects()) {
        if (project.containsMember(currentUser->getId())) {
            std::cout << project << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "[System] No joined projects." << std::endl;
    }

}