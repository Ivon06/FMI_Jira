#pragma once
#include "Command.h"

class FinishStageCommand : public Command {
public:
    explicit FinishStageCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};