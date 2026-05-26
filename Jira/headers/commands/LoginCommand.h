#pragma once
#include "Command.h"

class LoginCommand : public Command {
public:
    explicit LoginCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};