#pragma once
#include "Command.h"

class FinalizeProjectCommand : public Command {
public:
    explicit FinalizeProjectCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};