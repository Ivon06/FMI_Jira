#pragma once
#include "Command.h"

class SearchTasksCommand : public Command {
public:
    explicit SearchTasksCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};