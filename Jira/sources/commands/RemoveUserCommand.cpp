#include "../../headers/commands/RemoveUserCommand.h"
#include "../../headers/services/ProjectService.h"

#include <iostream>
#include <stdexcept>

RemoveUserCommand::RemoveUserCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void RemoveUserCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: remove-user <username>");
    }

   ProjectService::removeUser(context, args[0]);

    std::cout << "[System] User '" << args[0] << "' removed successfully." << std::endl;
}