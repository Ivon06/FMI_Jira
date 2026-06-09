#pragma once
#include "Command.h"

class CreateTaskCommand : public Command {
public:
    explicit CreateTaskCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};