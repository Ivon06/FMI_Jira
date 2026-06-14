#pragma once
#include "Command.h"

class StageReportCommand : public Command {
public:
    explicit StageReportCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};