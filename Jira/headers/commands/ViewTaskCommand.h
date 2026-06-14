#pragma once
#include "Command.h"

class ViewTaskCommand : public Command {
public:
    explicit ViewTaskCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};