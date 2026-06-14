#pragma once
#include "Command.h"

class ViewProjectCommand : public Command {
public:
    explicit ViewProjectCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};