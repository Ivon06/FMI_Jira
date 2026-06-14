#pragma once
#include "Command.h"

class UpcomingTasksCommand : public Command {
public:
    explicit UpcomingTasksCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};