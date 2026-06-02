#include "../../headers/commands/FinalizeProjectCommand.h"
#include "../../headers/services/ProjectService.h"

#include <iostream>
#include <stdexcept>

FinalizeProjectCommand::FinalizeProjectCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void FinalizeProjectCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: finalize-project <project_name>");
    }

    ProjectService::finalizeProject(context, args[0]);

    std::cout << "[System] Project marked as Finished.\n";
}