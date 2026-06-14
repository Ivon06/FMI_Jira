#include "..\..\headers\commands\ViewHistoryCommand.h"
#include "..\..\headers\services\TaskService.h"

ViewHistoryCommand::ViewHistoryCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void ViewHistoryCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument(
            "Usage: view-history <task_id>");
    }

    const auto& history =
        TaskService::getHistory(
            context,
            std::stoul(args[0]));

    if (history.empty()) {
        std::cout << "[System] No history available."
            << std::endl;
        return;
    }

    for (const auto& entry : history) {
        std::cout << entry << std::endl;
    }
}