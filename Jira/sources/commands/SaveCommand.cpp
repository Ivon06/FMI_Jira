#include "../../headers/commands/SaveCommand.h"
#include "../../headers/services/DataService.h"

#include <iostream>
#include <stdexcept>

SaveCommand::SaveCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void SaveCommand::execute(Context& context) {
    if (!args.empty()) {
        throw std::invalid_argument("Usage: save");
    }

    DataService::save(context);

    std::cout << "[System] Data saved successfully." << std::endl;
}