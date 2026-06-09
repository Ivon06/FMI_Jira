#pragma once
#include "Command.h"

class AssignTaskCommand : public Command {
public:
    explicit AssignTaskCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};