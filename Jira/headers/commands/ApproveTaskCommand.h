#pragma once
#include "Command.h"

class ApproveTaskCommand : public Command {
public:
    explicit ApproveTaskCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};