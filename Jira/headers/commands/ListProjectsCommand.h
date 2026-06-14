#pragma once
#include "Command.h"

class ListProjectsCommand : public Command {
public:
    explicit ListProjectsCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};