#include "../../headers/commands/AddCommentCommand.h"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

AddCommentCommand::AddCommentCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void AddCommentCommand::execute(Context& context) {

    if (args.size() < 2) {
        throw std::invalid_argument(
            "Usage: add-comment <task_id> <comment>");
    }

    std::string comment;

    for (size_t i = 1; i < args.size(); i++) {

        if (i > 1) {
            comment += " ";
        }

        comment += args[i];
    }

    TaskService::addComment(
        context,
        std::stoul(args[0]),
        comment);
}