#pragma once
#include "Command.h"

class RegisterCommand : public Command {
public:
    explicit RegisterCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};