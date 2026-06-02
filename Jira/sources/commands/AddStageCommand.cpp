#include "../../headers/commands/AddStageCommand.h"
#include "../../headers/services/StageService.h"

#include <iostream>
#include <stdexcept>
#include <ctime>

AddStageCommand::AddStageCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void AddStageCommand::execute(Context& context) {
    if (args.size() != 4) {
        throw std::invalid_argument("Usage: add-stage <project_name> <stage_name> <start_timestamp> <end_timestamp>");
    }

    std::time_t startDate = static_cast<std::time_t>(std::stoll(args[2]));
    std::time_t endDate = static_cast<std::time_t>(std::stoll(args[3]));

    StageService::addStage(context, args[0], args[1], startDate, endDate);

    std::cout << "[System] Stage '" << args[1] << "' added to project '" << args[0] << "'.\n";
}