#pragma once
#include "Command.h"

class LogoutCommand : public Command {
public:
    explicit LogoutCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};