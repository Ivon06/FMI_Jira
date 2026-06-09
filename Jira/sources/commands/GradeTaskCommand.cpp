#include "../../headers/commands/GradeTaskCommand.h"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

GradeTaskCommand::GradeTaskCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void GradeTaskCommand::execute(Context& context) {

    if (args.size() != 2) {
        throw std::invalid_argument(
            "Usage: grade-task <task_id> <grade>");
    }

    TaskService::gradeTask(
        context,
        std::stoul(args[0]),
        std::stod(args[1]));
}