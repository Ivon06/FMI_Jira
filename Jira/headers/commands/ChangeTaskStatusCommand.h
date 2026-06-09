#pragma once
#include "Command.h"

class ChangeTaskStatusCommand : public Command {
public:
    explicit ChangeTaskStatusCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};