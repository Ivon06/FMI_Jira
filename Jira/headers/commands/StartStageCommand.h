#pragma once
#include "Command.h"

class StartStageCommand : public Command {
public:
    explicit StartStageCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};