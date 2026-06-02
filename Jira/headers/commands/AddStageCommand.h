#pragma once
#include "Command.h"

class AddStageCommand : public Command {
public:
    explicit AddStageCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};