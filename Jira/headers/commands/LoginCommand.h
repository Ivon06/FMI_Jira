#pragma once
#include "Command.h"

class LoginCommand : public Command {
public:
    LoginCommand(std::vector<std::string>& args);
    void execute(Context& context) override;
};