#include "../../headers/commands/LogoutCommand.h"
#include "../../headers/services/UserService.h"
#include <iostream>
#include <stdexcept>

void LogoutCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: logout");
    }

    UserService::logout(context);

    std::cout << "[System] Successfully logged out.\n";
}