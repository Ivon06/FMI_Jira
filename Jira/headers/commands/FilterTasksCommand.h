#pragma once
#include "Command.h"

class FilterTasksCommand : public Command {
public:
    explicit FilterTasksCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};