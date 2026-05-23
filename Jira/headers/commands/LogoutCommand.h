#pragma once
#include "Command.h"

class LogoutCommand : public Command {
public:
    LogoutCommand(std::vector<std::string>& args) : Command(args) {}
    void execute(Context& context) override;
};