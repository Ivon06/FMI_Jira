#pragma once
#include "Command.h"

class CreateProjectCommand : public Command {
public:

    explicit CreateProjectCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};