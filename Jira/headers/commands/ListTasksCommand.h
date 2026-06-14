#pragma once
#include "Command.h"

class ListTasksCommand : public Command {
public:
    explicit ListTasksCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};