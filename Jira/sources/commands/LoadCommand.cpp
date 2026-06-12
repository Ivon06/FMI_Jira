#include "../../headers/commands/LoadCommand.h"
#include "../../headers/services/DataService.h"

#include <iostream>
#include <stdexcept>

LoadCommand::LoadCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void LoadCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: load");
    }

    DataService::load(context);

    std::cout << "[System] Data loaded successfully." << std::endl;
}