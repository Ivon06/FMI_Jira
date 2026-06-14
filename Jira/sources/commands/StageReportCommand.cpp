#include "../../headers/commands/StageReportCommand.h"
#include "../../headers/services/UserService.h"
#include "../../headers/services/ProjectService.h"

#include <iostream>
#include <stdexcept>

StageReportCommand::StageReportCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void StageReportCommand::execute(Context& context) {
    if (args.size() != 2) {
        throw std::invalid_argument("Usage: stage-report <project_name> <stage_name>");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr ||
        (currentUser->getRole() != UserRole::Lecturer &&
            currentUser->getRole() != UserRole::TeachingAssistant)) {
        throw std::runtime_error("Only lecturer or teaching assistant can view stage reports.");
    }

    Project* project = ProjectService::findProjectByName(context, args[0]);

    if (project == nullptr) {
        throw std::invalid_argument("Project does not exist.");
    }

    const Stage* stage = project->getStageByName(args[1]);

    if (stage == nullptr) {
        throw std::invalid_argument("Stage does not exist.");
    }

    std::cout << "[Stage Report]" << std::endl;
    std::cout << *stage;

    for (unsigned int taskId : stage->getTaskIds()) {
        for (const Task& task : context.getTasks()) {
            if (task.getId() == taskId) {
                std::cout << task << std::endl;
            }
        }
    }
}