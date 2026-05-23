#pragma once
#include "Command.h"

class RegisterCommand : public Command {
public:
	RegisterCommand(std::vector<std::string>& args) : Command(args) {}
    void execute(Context& context) override;
};