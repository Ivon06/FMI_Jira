#include "../../headers/commands/LoginCommand.h"
#include "../../headers/services/UserService.h"
#include "../../headers/users/UserRole.hpp"
#include <iostream>
#include <stdexcept>

LoginCommand::LoginCommand(std::vector<std::string>& args) : Command(args) {}

void LoginCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument("Usage: login <username> <password>");
    }

    UserService::login(context, args[0], args[1]);

    User* currentUser = UserService::getCurrentUser(context);

    std::cout << "[System] Successfully logged in. Role: "
        << roleToString(currentUser->getRole())
        << ".\n";
}