#pragma once
#include "Command.h"

class HelpCommand : public Command {
public:
    explicit HelpCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};