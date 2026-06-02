#include "../../headers/commands/FinishStageCommand.h"
#include "../../headers/services/StageService.h"

#include <iostream>
#include <stdexcept>

FinishStageCommand::FinishStageCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void FinishStageCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument("Usage: finish-stage <project_name> <stage_name>");
    }

    StageService::finishStage(context, args[0], args[1]);

    std::cout << "[System] Stage '" << args[1] << "' finished.\n";
}