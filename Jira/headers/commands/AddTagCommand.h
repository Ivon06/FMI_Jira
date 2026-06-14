#pragma once
#include "Command.h"

class AddTagCommand : public Command {
public:
    explicit AddTagCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};