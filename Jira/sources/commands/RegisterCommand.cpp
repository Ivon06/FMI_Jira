#include "../../headers/commands/RegisterCommand.h"
#include "../../headers/services/UserService.h"
#include <iostream>
#include <stdexcept>

RegisterCommand::RegisterCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void RegisterCommand::execute(Context& context) {
    
    if (args.size() != 3) {
        throw std::invalid_argument(
            "Usage: register <username> <password> <role>");
    }

    UserService::registerUser(context, args[0], args[1], args[2]);

    std::cout << "[System] User '"
        << args[0]
        << "' registered.\n";
}