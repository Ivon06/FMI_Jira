#pragma once
#include "Command.h"

class ListAllTasksCommand : public Command {
public:
    explicit ListAllTasksCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};