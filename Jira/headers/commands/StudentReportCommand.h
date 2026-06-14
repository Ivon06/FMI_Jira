#pragma once
#include "Command.h"

class StudentReportCommand : public Command {
public:
    explicit StudentReportCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};