#pragma once
#include "Command.h"

class LoadCommand : public Command {
public:
    explicit LoadCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};