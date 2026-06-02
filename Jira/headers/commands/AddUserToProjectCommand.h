#pragma once
#include "Command.h"

class AddUserToProjectCommand : public Command {
public:
    explicit AddUserToProjectCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};