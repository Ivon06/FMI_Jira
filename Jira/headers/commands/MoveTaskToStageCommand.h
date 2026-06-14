#pragma once
#include "Command.h"

class MoveTaskToStageCommand : public Command {
public:
    explicit MoveTaskToStageCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};