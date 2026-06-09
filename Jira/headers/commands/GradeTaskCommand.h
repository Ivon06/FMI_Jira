#pragma once
#include "Command.h"

class GradeTaskCommand : public Command {
public:
    explicit GradeTaskCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};