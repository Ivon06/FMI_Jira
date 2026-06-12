#pragma once
#include "Command.h"

class SaveCommand : public Command {
public:
    explicit SaveCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};