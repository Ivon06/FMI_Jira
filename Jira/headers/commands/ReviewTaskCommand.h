#pragma once
#include "Command.h"

class ReviewTaskCommand : public Command {
public:
    explicit ReviewTaskCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};