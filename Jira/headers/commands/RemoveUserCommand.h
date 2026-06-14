#pragma once
#include "Command.h"

class RemoveUserCommand : public Command {
public:
    explicit RemoveUserCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};