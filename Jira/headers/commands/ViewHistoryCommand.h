#pragma once
#include "Command.h"

class ViewHistoryCommand : public Command {
public:
    explicit ViewHistoryCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};