#pragma once
#include "Command.h"

class ViewProfileCommand : public Command {
public:
    explicit ViewProfileCommand(const std::vector<std::string>& args);
    void execute(Context& context) override;
};