#include "../../headers/commands/StartStageCommand.h"
#include "../../headers/services/StageService.h"

#include <iostream>
#include <stdexcept>

StartStageCommand::StartStageCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void StartStageCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument("Usage: start-stage <project_name> <stage_name>");
    }

    StageService::startStage(context, args[0], args[1]);

    std::cout << "[System] Stage '" << args[1] << "' started.\n";
}