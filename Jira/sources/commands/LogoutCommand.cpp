#include "../../headers/commands/LogoutCommand.h"
#include "../../headers/services/UserService.h"
#include <iostream>
#include <stdexcept>

LogoutCommand::LogoutCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void LogoutCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: logout");
    }

    UserService::logout(context);

    std::cout << "[System] Successfully logged out.\n";
}