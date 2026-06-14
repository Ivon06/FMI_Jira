#pragma once
#include "Command.h"

class ListAllProjectsCommand : public Command {
public:
    explicit ListAllProjectsCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};