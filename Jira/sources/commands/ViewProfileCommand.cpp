#include "../../headers/commands/ViewProfileCommand.h"
#include "../../headers/services/UserService.h"
#include <iostream>
#include <stdexcept>

ViewProfileCommand::ViewProfileCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ViewProfileCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: view-profile");
    }

    User* user = UserService::getCurrentUser(context);

    if (user == nullptr) {
        throw std::runtime_error("No logged user.");
    }

    std::cout << *user;
}