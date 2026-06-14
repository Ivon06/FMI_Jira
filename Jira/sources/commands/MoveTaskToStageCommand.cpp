#include "../../headers/commands/MoveTaskToStageCommand.h"
#include "../../headers/services/StageService.h"

#include <iostream>
#include <stdexcept>

MoveTaskToStageCommand::MoveTaskToStageCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void MoveTaskToStageCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument("Usage: move-task-to-stage <task_id> <stage_name>");
    }

    StageService::moveTaskToStage(context, std::stoul(args[0]), args[1]);

    std::cout << "[System] Task moved to " << args[1] << "." << std::endl;
}