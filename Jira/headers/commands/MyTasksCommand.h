#pragma once
#include "Command.h"

class MyTasksCommand : public Command {
public:
    explicit MyTasksCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};