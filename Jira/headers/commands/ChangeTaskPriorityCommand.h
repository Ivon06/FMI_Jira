#pragma once
#include "Command.h"

class ChangeTaskPriorityCommand : public Command {
public:
    explicit ChangeTaskPriorityCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};