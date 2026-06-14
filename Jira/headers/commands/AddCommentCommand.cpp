#include "../../headers/commands/AddCommentCommand.h"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

AddCommentCommand::AddCommentCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void AddCommentCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: add-comment <task_id>");
    }

    std::string content;

    std::cout << "Comment: ";
    std::getline(std::cin, content);

    TaskService::addComment(context, std::stoul(args[0]), content);

    std::cout << "[System] Comment added." << std::endl;
}